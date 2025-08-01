# ====== START: For Testing =====

set(REPORT_FORMAT "xml")  # xml or json
set(GTEST_DIR "${REPO_LOC}googletest")
add_subdirectory("${GTEST_DIR}" "${CMAKE_BINARY_DIR}/googletest_build")
enable_testing()
include(GoogleTest)
add_subdirectory(tests)

# ====== END: For Testing =====