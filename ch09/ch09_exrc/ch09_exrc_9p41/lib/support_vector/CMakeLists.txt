# lib/support_vector/CMakeLists.txt
set(LIBRARY_NAME "support_vector")
add_library(
    ${LIBRARY_NAME}
    ${LIBRARY_NAME}.cpp
)

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

file(APPEND ${FILE_CPPCHECK_SOURCES} "${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_NAME}.cpp\n")
file(APPEND ${FILE_CPPCHECK_INCLUDES} "${CMAKE_CURRENT_SOURCE_DIR}\n")