# tests/CMakeLists.txt

add_compile_options(${COVERAGE_COMPILER_FLAGS})
add_link_options(${COVERAGE_COMPILER_FLAGS})

add_subdirectory(displaySeqContainer_test)
add_subdirectory(support_forwardList_test)
add_subdirectory(support_list_test)
add_subdirectory(support_vector_test)