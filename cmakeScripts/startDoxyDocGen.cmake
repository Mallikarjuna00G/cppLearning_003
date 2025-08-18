# ====== START: For DOXYGEN Documentation =====

include(${REPO_LOC_CMAKE_SCRIPTS}/checkForDoxygen.cmake)
include(${REPO_LOC_CMAKE_SCRIPTS}/checkForPlantUML.cmake)

# Include custom CMake script for Doxygen documentation generation
include("${REPO_LOC_CMAKE_SCRIPTS}/DoxygenDoc.cmake")

# ====== END: For DOXYGEN Documentation =====