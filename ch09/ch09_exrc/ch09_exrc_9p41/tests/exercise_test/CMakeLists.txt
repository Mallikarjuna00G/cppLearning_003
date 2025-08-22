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
)

add_test(
    NAME ${testSuite}
    COMMAND ${testSuite} --gtest_output=${REPORT_FORMAT}:${CMAKE_BINARY_DIR}/Testing/Reports/${testSuite}.xml
)