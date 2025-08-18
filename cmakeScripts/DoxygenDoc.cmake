# DoxygenDoc.cmake

# This script provides a CMake function to add Doxygen documentation targets.
# It expects to be included from the top-level CMakeLists.txt or a subproject.

# =========================================================================
# CMake Function: add_my_doxygen_target
# -------------------------------------------------------------------------
# This function creates a Doxygen documentation target using named arguments.
#
# Usage:
#   add_my_doxygen_target(
#       <PREFIX>                     # Required: Unique prefix for internal variables (e.g., 'DOC_TARGET')
#       NAME <target_name>           # Required: Name of the CMake target (e.g., 'doc')
#       PROJECT_DISPLAY_NAME <name>  # Required: Display name for the Doxygen docs
#       PROJECT_VERSION <version>    # Required: Version string for Doxygen
#       OUTPUT_SUBDIR <subdir_name>  # Required: Subdirectory for HTML output (e.g., "doc/html")
#       SOURCES <path1> [<path2>...] # Required: List of source dirs/files for Doxygen to scan
#       [EXCLUDE_PATTERNS <pat1> [<pat2>...]] # Optional: List of patterns to exclude
#       [GENERATE_LATEX]             # Optional: Flag to generate LaTeX docs
#       [ALL]                        # Optional: Flag to add target to default build (e.g., 'make')
#   )
# =========================================================================
function(add_my_doxygen_target) # PREFIX is a required positional argument for cmake_parse_arguments

    set(HOMEPAGE_MD_FILE "README.md")
    set(DEFAULT_EXCLUDES 
        "${CMAKE_SOURCE_DIR}/build"
        "${CMAKE_SOURCE_DIR}/cmakeScripts"
        "${CMAKE_SOURCE_DIR}/test"
        "${CMAKE_SOURCE_DIR}/_deps"
    )
    set(DOC_EXCLUDES ${DEFAULT_EXCLUDES})

    # Handle EXCLUDE_PATTERNS - combine default with user-provided
    set(DEFAULT_EXCLUDE_PATTERNS
        "${CMAKE_SOURCE_DIR}/build/*"
        "${CMAKE_SOURCE_DIR}/_deps/*"
        "${CMAKE_SOURCE_DIR}/cmake_scripts/*"
        "${CMAKE_SOURCE_DIR}/test/*"
    )
    set(DOC_EXCLUDE_PATTERNS ${DEFAULT_EXCLUDE_PATTERNS})
    
    # Define the arguments for cmake_parse_arguments
    set(options ALL GENERATE_LATEX) # Flags (boolean options)
    set(oneValueArgs PREFIX PRJ_NAME PRJ_BRIEF HOMEPAGE_MD_FILE) # Options that take one value
    set(multiValueArgs SOURCES EXCLUDE EXCLUDE_PATTERNS) # Options that take multiple values (lists)

    # message(STATUS "DEBUG: Contents of ARGN BEFORE cmake_parse_arguments: '${ARGN}'")
    # Parse the arguments. All arguments after the PREFIX are parsed.
    # The parsed values will be stored in variables prefixed with `_${PREFIX}_`.
    cmake_parse_arguments("${PREFIX}" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Check for required arguments
    if (NOT ${PREFIX}_PRJ_NAME OR NOT ${PREFIX}_SOURCES)
        message(FATAL_ERROR "add_my_doxygen_target: Missing required arguments.")
    endif()

    if (${PREFIX}_HOMEPAGE_MD_FILE)
        set(HOMEPAGE_MD_FILE ${PREFIX}_HOMEPAGE_MD_FILE)
    endif()
    if (${PREFIX}_EXCLUDE)
        set(DOC_EXCLUDES ${PREFIX}_EXCLUDE)
    endif()
    if (${PREFIX}_EXCLUDE_PATTERNS)
        set(DOC_EXCLUDE_PATTERNS ${PREFIX}_EXCLUDE_PATTERNS)
    endif()

    include(${REPO_LOC_CMAKE_SCRIPTS}/configureDoxygen.cmake)

    # Add the custom target using doxygen_add_docs
    doxygen_add_docs("doc" # Use the parsed target name
        ${${PREFIX}_SOURCES}           # Use the parsed list of sources
        "${HOMEPAGE_MD_FILE}"
        COMMENT "Generating Doxygen documentation for ${${PREFIX}_PRJ_NAME}"
        ${${PREFIX}_ALL}               # Pass the ALL flag if present
    )
    message(STATUS "Doxygen target '${${PREFIX}_PRJ_NAME}' configured. Output will be in: ${DOXYGEN_OUTPUT_DIRECTORY}")

endfunction()