set(LIBRARY_NAME "exercise")

add_compile_options(${COVERAGE_COMPILER_FLAGS})
add_link_options(${COVERAGE_COMPILER_FLAGS})

add_library(
    ${LIBRARY_NAME}
    ${LIBRARY_NAME}.cpp
)

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)