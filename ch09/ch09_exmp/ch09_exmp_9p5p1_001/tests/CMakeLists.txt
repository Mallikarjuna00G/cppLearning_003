# tests/CMakeLists.txt

add_compile_options(${COVERAGE_COMPILER_FLAGS})
add_link_options(${COVERAGE_COMPILER_FLAGS})

add_subdirectory(exercise_test)

include("${REPO_LOC_CMAKE_SCRIPTS}/genCTestReports.cmake")
include("${REPO_LOC_CMAKE_SCRIPTS}/genJUnit2HtmlReports.cmake")
include("${REPO_LOC_CMAKE_SCRIPTS}/genCoverageReportGen.cmake")