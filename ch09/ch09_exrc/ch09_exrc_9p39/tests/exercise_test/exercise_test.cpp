#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream> // Required for file I/O

#if defined(_WIN32)
    #include <direct.h>   // For _mkdir on Windows
#else
    #include <sys/stat.h> // For mkdir on POSIX
#endif

#include "exercise.hpp"
#include "displaySeqContainer.hpp"
#include "gtest/gtest.h"

using std::vector;
using std::cout;
using std::endl;

// A test fixture is a good practice for this type of test
// to ensure the streams are always restored.
class ExrcTest : public ::testing::Test {
protected:
    // Pointers to the original stream buffers
    std::streambuf* original_cout_buffer;
    std::streambuf* original_cin_buffer;

    // String streams to capture and provide data
    std::stringstream captured_output;
    std::stringstream mock_input;

    void SetUp() override {
        // Save the original stream buffers
        original_cout_buffer = std::cout.rdbuf();
        original_cin_buffer = std::cin.rdbuf();

        // Redirect cout and cin to our string streams
        std::cout.rdbuf(captured_output.rdbuf());
        std::cin.rdbuf(mock_input.rdbuf());

        // Create a directory for the output if it doesn't exist.
        // This is the C++11 compatible way to create a directory.
        createDirectory(executionLogsFolderName);
    }

    void TearDown() override {
        // Restore the original stream buffers
        std::cout.rdbuf(original_cout_buffer);
        std::cin.rdbuf(original_cin_buffer);
    }

    // A function to create a directory that works with C++11.
    bool createDirectory(const std::string& path) {
        #if defined(_WIN32)
            // Use _mkdir for Windows
            return _mkdir(path.c_str()) == 0 || errno == EEXIST;
        #else
            // Use mkdir for POSIX systems (Linux, macOS, etc.)
            return mkdir(path.c_str(), 0777) == 0 || errno == EEXIST;
        #endif
    }

    std::string output_filename = "";
    std::string executionLogsFolderName = "executionLogs";

    void determineOutputFileName() {
        // Get the current test info to create a unique filename.
        const ::testing::TestInfo* const test_info = ::testing::UnitTest::GetInstance()->current_test_info();
        std::string fixture_name = test_info->test_case_name();
        std::string test_name = test_info->name();
        
        // Construct the dynamic filename.
        output_filename = executionLogsFolderName + std::string("/") + fixture_name + "_" + test_name + ".txt";
    }

    void writeExecutionToFile() {
        determineOutputFileName();
        // Write the captured output to a file.
        std::ofstream outputFile(output_filename);
        if (outputFile.is_open()) {
            outputFile << "======================================================\n";
            outputFile << "   Provided input (starts here)   \n";
            outputFile << "======================================================\n\n";
            outputFile << mock_input.str();
            outputFile << "\n\n======================================================\n";
            outputFile << "     Provided input (ends here)   \n";
            outputFile << "======================================================\n";
            
            outputFile << "======================================================\n";
            outputFile << "   Captured Output from exercise() (starts here)   \n";
            outputFile << "======================================================\n\n";
            outputFile << captured_output.str();
            outputFile << "\n\n======================================================\n";
            outputFile << "     Captured Output from exercise() (ends here)   \n";
            outputFile << "======================================================\n";
            outputFile.close();
        }
    }
};

TEST_F(ExrcTest, NormalExecutionWithInput) {
    // Provide a series of words as mock input to the stringstream
    mock_input << "Hello World C++ Unit Test";
    
    // Call the original function. It will now read from our mock_input stream.
    int result = exercise();

    // Check that the function returns successfully
    ASSERT_EQ(result, EXIT_SUCCESS);
    writeExecutionToFile();

    std::string output_string = captured_output.str();
    
    // The checks now reflect the correct output based on 5 input words.
    EXPECT_NE(output_string.find("On fresh declaration"), std::string::npos);
    EXPECT_NE(output_string.find("On reserve(1024)"), std::string::npos);
    EXPECT_NE(output_string.find("While feeding"), std::string::npos);
    EXPECT_NE(output_string.find("After resize"), std::string::npos);
    
    // Check for the initial state
    EXPECT_NE(output_string.find("0 : 0"), std::string::npos);
    // Check after reserve()
    EXPECT_NE(output_string.find("0 : 1024"), std::string::npos);
    // Check after adding 5 words (size: 5, capacity: 1024)
    EXPECT_NE(output_string.find("5 : 1024"), std::string::npos);
    // Check after resize (size: 5 + 5/2 = 7, capacity: 1024)
    EXPECT_NE(output_string.find("7 : 1024"), std::string::npos);

}

TEST_F(ExrcTest, NormalExecutionWithInput2) {
    // Provide a series of words as mock input to the stringstream
    mock_input << "They ain't gonna know what hit them\nVenom...\nVenom...\nVENOM!!!\n";
    
    // Call the original function. It will now read from our mock_input stream.
    int result = exercise();

    // Check that the function returns successfully
    ASSERT_EQ(result, EXIT_SUCCESS);
    writeExecutionToFile();

    std::string output_string = captured_output.str();
    
    // The checks now reflect the correct output based on 5 input words.
    EXPECT_NE(output_string.find("On fresh declaration"), std::string::npos);
    EXPECT_NE(output_string.find("On reserve(1024)"), std::string::npos);
    EXPECT_NE(output_string.find("While feeding"), std::string::npos);
    EXPECT_NE(output_string.find("After resize"), std::string::npos);
    
    // Check for the initial state
    EXPECT_NE(output_string.find("0 : 0"), std::string::npos);
    // Check after reserve()
    EXPECT_NE(output_string.find("0 : 1024"), std::string::npos);
    // Check after adding 5 words (size: 5, capacity: 1024)
    EXPECT_NE(output_string.find("5 : 1024"), std::string::npos);
    // Check after resize (size: 5 + 5/2 = 7, capacity: 1024)
    EXPECT_NE(output_string.find("7 : 1024"), std::string::npos);
    EXPECT_NE(output_string.find("Vector (size : capacity) :: 15 : 1024"), std::string::npos);

}

