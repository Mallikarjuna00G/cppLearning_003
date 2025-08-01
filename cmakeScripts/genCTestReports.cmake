
# To generate test report altogether. It generates test report different than googletest test report.
add_custom_target(
    ctestXMLReports
    COMMAND ${CMAKE_CTEST_COMMAND} -D ExperimentalTest
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running CTest to generate reports."
)