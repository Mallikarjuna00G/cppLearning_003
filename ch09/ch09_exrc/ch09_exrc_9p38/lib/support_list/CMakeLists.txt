# lib/support_list/CMakeLists.txt
set(LIBRARY_NAME "support_list")
add_library(
    ${LIBRARY_NAME}
    ${LIBRARY_NAME}.cpp
)

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)