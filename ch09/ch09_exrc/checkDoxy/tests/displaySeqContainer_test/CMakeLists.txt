# tests/displaySeqContainer_test
set(testUnit "displaySeqContainer")
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

gtest_discover_tests(${testSuite})