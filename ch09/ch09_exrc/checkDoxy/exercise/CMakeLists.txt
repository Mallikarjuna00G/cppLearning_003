# lib/displaySeqContainer/CMakeLists.txt
set(LIBRARY_NAME "exercise")
add_library(
    ${LIBRARY_NAME}
    ${LIBRARY_NAME}.cpp
)

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
    ${LIBRARY_NAME}
    PRIVATE
    "displaySeqContainer"
    # "support_vector"
    # "support_list"
    # "support_forwardList"
)