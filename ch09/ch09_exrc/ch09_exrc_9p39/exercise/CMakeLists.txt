set(LIBRARY_NAME "exercise")

add_library(
    ${LIBRARY_NAME}
    ${LIBRARY_NAME}.cpp
)

target_link_libraries(
    ${LIBRARY_NAME}
    "displaySeqContainer"
)

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)