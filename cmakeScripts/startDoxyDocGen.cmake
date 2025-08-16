# ====== START: For DOXYGEN Documentation =====

include(${REPO_LOC_CMAKE_SCRIPTS}/checkForDoxygen.cmake)
include(${REPO_LOC_CMAKE_SCRIPTS}/checkForPlantUML.cmake)

# Include custom CMake script for Doxygen documentation generation
include("${REPO_LOC_CMAKE_SCRIPTS}/DoxygenDoc.cmake")

# Call the function defined in DoxygenDoc.cmake to add our project's documentation target
# Using named arguments makes the call much clearer.
add_my_doxygen_target(
    PREFIX "MY_SIMPLE_DEBUG_PREFIX"
    PRJ_NAME "${PROJECT_NAME}"
    SOURCES 
        "${CMAKE_SOURCE_DIR}/main.cpp"
        "${CMAKE_SOURCE_DIR}/exercise/"
        "${CMAKE_SOURCE_DIR}/lib/"
    PRJ_BRIEF ""
    )


# ====== END: For DOXYGEN Documentation =====