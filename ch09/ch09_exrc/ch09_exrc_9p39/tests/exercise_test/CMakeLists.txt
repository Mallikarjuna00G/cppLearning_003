# tests/exercise_test
set(testUnit "exercise")
set(testSuite "${testUnit}_test")
add_executable(
    ${testSuite}
    "${testSuite}.cpp"
)

target_link_libraries(
    ${testSuite} PRIVATE
    ${testUnit}
    gtest_main

    "displaySeqContainer"
)

gtest_discover_tests(
    ${testSuite}
    PROPERTIES
        ENVIRONMENT "GTEST_OUTPUT=xml:${CMAKE_BINARY_DIR}/Testing/Reports/${testSuite}Report.${REPORT_FORMAT}"
)
