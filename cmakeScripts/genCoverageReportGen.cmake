# ====== START: Coverage Report Generation =====
# Add this after your enable_testing() and test discovery commands

# Find gcovr to generate the report
find_program(GCOVR_COMMAND gcovr)
if(NOT GCOVR_COMMAND)
    message(FATAL_ERROR "gcovr not found. Please install it with 'sudo apt install gcovr' or 'pip install gcovr'.")
endif()

add_custom_target(
    coverage_report
    # Create the output directory if it doesn't exist.
    COMMAND ${CMAKE_COMMAND} -E make_directory unitTest_Coverage
    # Run the gcovr command and output to the new directory.
    COMMAND ${GCOVR_COMMAND} --root ${CMAKE_SOURCE_DIR}  --exclude-directories "tests/" --exclude-directories "CMakeFiles/" --html --html-details -o unitTest_Coverage/coverage.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating code coverage report in unitTest_Coverage folder..."
    # Ensure this target depends on the tests being run
    # DEPENDS your_test_suite_executable_name
)

# You would then run your tests separately to generate the .gcda files,
# and then run this custom target to generate the report.
# For example:
# cmake --build . --target your_test_suite_executable_name
# ctest
# cmake --build . --target coverage_report

# ====== END: Coverage Report Generation =====