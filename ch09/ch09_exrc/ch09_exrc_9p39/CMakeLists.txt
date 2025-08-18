cmake_minimum_required(VERSION 3.14)
project(ch09_exrc_9p38 LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -pedantic)
set(COVERAGE_COMPILER_FLAGS "--coverage")

add_subdirectory(exercise)
add_subdirectory(lib)

add_custom_target(
    run_app
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running application ${PROJECT_NAME}"
)

add_custom_target(
    help2
    COMMAND ${CMAKE_COMMAND} -E echo "Helpful targets for this project:"
    COMMAND ${CMAKE_COMMAND} -E echo "  -->  run_app - Run the application"
    COMMAND ${CMAKE_COMMAND} -E echo "  -->  doc     - Generate Doxygen documentation"
    COMMENT "Displays help information about custom targets."
    VERBATIM
)

add_executable(
    ${PROJECT_NAME}
    main.cpp
)


target_compile_options(
    ${PROJECT_NAME} PRIVATE
    ${CMAKE_CXX_FLAGS}
    ${COVERAGE_COMPILER_FLAGS}
)

target_link_options(
    ${PROJECT_NAME} PRIVATE
    ${CMAKE_CXX_FLAGS}
    ${COVERAGE_COMPILER_FLAGS}
)

target_link_libraries(
    ${PROJECT_NAME}
    exercise
)

set(REPO_LOC "${CMAKE_SOURCE_DIR}/../../../")
set(REPO_LOC_CMAKE_SCRIPTS "${REPO_LOC}/cmakeScripts")

include(${REPO_LOC_CMAKE_SCRIPTS}/startDoxyDocGen.cmake)

# Call the function defined in DoxygenDoc.cmake to add our project's documentation target
# Using named arguments makes the call much clearer.
add_my_doxygen_target(
    PREFIX "MY_SIMPLE_DEBUG_PREFIX"
    PRJ_NAME "${PROJECT_NAME}"
    SOURCES 
        "${CMAKE_SOURCE_DIR}/main.cpp"
        "${CMAKE_SOURCE_DIR}/exercise/"
        "${CMAKE_SOURCE_DIR}/lib/"
    PRJ_BRIEF "Documentation for ${PROJECT_NAME}"
    EXCLUDE
        "${CMAKE_SOURCE_DIR}/build"
)

include("${REPO_LOC_CMAKE_SCRIPTS}/addForTesting.cmake")