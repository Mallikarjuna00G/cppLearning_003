# lib/CMakeLists.txt

add_compile_options(${COVERAGE_COMPILER_FLAGS})
add_link_options(${COVERAGE_COMPILER_FLAGS})

add_subdirectory(displaySeqContainer)
add_subdirectory(support_forwardList)
add_subdirectory(support_list)
add_subdirectory(support_vector)