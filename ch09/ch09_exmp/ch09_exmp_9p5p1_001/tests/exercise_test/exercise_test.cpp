#include <string>
#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"

using ::testing::MatchesRegex;

// A test fixture is a good practice for this type of test
// to hold common data and setup/teardown logic.
class ExrcTest : public ::testing::Test {
protected:
    const char* cp = "Hello World!!!"; // Null-terminated C-style string.
    char noNull[2] = {'H', 'i'}; // not null terminated
};

TEST_F(ExrcTest, copyUptoNull) {
    // The constructor of std::string from a const char* should copy characters
    // until it encounters the null terminator.
    std::string s1(cp);

    // A test needs an assertion to verify behavior. Without one, the test
    // only checks that the code doesn't crash.
    ASSERT_EQ(s1, "Hello World!!!");
    ASSERT_EQ(s1.size(), 14);
}

TEST_F(ExrcTest, copy2CharsfromnoNull) {
    std::string s2(noNull, 2);  // copy two characters from noNull

    ASSERT_EQ(s2, "Hi");
    ASSERT_EQ(s2.size(), 2);
}

TEST_F(ExrcTest, undefBehaviorWhenCharNotNullTerminated) {
    std::cerr << "⚠️  WARNING: This test case demonstrates a common undefined behavior issue where a non-null-terminated char array is passed to construct std::string.\nThe behavior is unpredictable and may cause a crash." << std::endl;

    std::string s3(noNull);  // undefined: noNull not null terminated

    EXPECT_EQ(s3, "Hi");
    EXPECT_EQ(s3.size(), 2);
}

TEST_F(ExrcTest, copyNcharsFromPosOfCStrMethod) {
    std::string s4(cp + 6, 5);  // Copy 5 characters starting at `cp[6];`

    ASSERT_EQ(s4, "World");
    ASSERT_EQ(s4.size(), 5);
}


TEST_F(ExrcTest, copyNpXcharsFromPosOfCStrMethod) {
    std::cerr << "⚠️  WARNING: This code demonstrates undefined behavior due to an explicit out-of-bounds read. The program may crash, or return garbage data, as the behavior is unpredictable." << std::endl;

    std::string s5(cp + 6, 25);  // Copy 5 characters starting at `cp[6];`

    EXPECT_THAT(s5, MatchesRegex("World.*"));
    EXPECT_EQ(s5.size(), 25);
}

TEST_F(ExrcTest, copyNpXcharsFromStr) {
    std::string s1(cp);
    std::string s6(s1, 6, 5);  // Copy 5 characters starting at `s1[6];`

    ASSERT_EQ(s6, "World");
    ASSERT_EQ(s6.size(), 5);
}

TEST_F(ExrcTest, copyNpXcharsFromStr2) {
    std::string s1(cp);
    std::string s6(s1, 6);  // Copy characters starting at `s1[6];` to the end

    ASSERT_EQ(s6, "World!!!");
    ASSERT_EQ(s6.size(), 8);
}

TEST_F(ExrcTest, copyNpXcharsFromStr3) {
    std::string s1(cp);
    std::string s6(s1, 6, 20);  // ok, copies only to end of s1; s7 == "World!!!"

    ASSERT_EQ(s6, "World!!!");
    ASSERT_EQ(s6.size(), 8);
}


TEST_F(ExrcTest, copyNpXcharsFromStrThrowOutOfRange) {
    std::string s1(cp);
    // throws an out_of_range exception

    ASSERT_THROW(std::string s6(s1, 16), std::out_of_range);
}