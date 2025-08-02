# DoxygenDoc.cmake

# This script provides a CMake function to add Doxygen documentation targets.
# It expects to be included from the top-level CMakeLists.txt or a subproject.

# Require dot, treat the other components as optional
find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)

if (NOT DOXYGEN_FOUND)
    message(WARNING "Doxygen not found. The 'add_my_doxygen_target' function will not be available or functional.")
    return() # Exit script if Doxygen is not found
endif()

message(STATUS "Doxygen found: ${DOXYGEN_EXECUTABLE} (version ${DOXYGEN_VERSION})")
message(STATUS "Graphviz dot found: ${DOXYGEN_DOT_EXECUTABLE}")

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

    # Define the arguments for cmake_parse_arguments
    set(options ALL GENERATE_LATEX) # Flags (boolean options)
    set(oneValueArgs PREFIX PRJ_NAME PRJ_BRIEF PROJECT_VERSION OUTPUT_SUBDIR) # Options that take one value
    set(multiValueArgs SOURCES EXCLUDE_PATTERNS) # Options that take multiple values (lists)

    message(STATUS "DEBUG: Contents of ARGN BEFORE cmake_parse_arguments: '${ARGN}'")
    # Parse the arguments. All arguments after the PREFIX are parsed.
    # The parsed values will be stored in variables prefixed with `_${PREFIX}_`.
    cmake_parse_arguments("${PREFIX}" "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Check for required arguments
    if (NOT ${PREFIX}_PRJ_NAME OR NOT ${PREFIX}_SOURCES)
        message(FATAL_ERROR "add_my_doxygen_target: Missing required arguments.")
    endif()

    # Configure Doxygen settings using the parsed arguments
    set(DOXYGEN_PROJECT_NAME        "${${PREFIX}_PRJ_NAME}")
    set(DOXYGEN_PROJECT_BRIEF       "${${PREFIX}_PRJ_BRIEF}")
    set(DOXYGEN_PROJECT_LOGO       "${REPO_LOC}/doc/cppLearning_003_logo.svg")
    set(DOXYGEN_GENERATE_HTML       YES)
    set(DOXYGEN_HTML_OUTPUT       "html")
    set(DOXYGEN_GENERATE_XML        NO)
    set(DOXYGEN_XML_OUTPUT        "xml")
    set(DOXYGEN_GENERATE_LATEX      NO) # Controlled by flag
    set(DOXYGEN_LATEX_OUTPUT      "latex") # Controlled by flag
    set(DOXYGEN_RECURSIVE           YES) # Still recursive for inputs

    set(DOXYGEN_EXTRACT_ALL         YES)
    set(DOXYGEN_EXTRACT_PRIVATE         YES)
    set(DOXYGEN_EXTRACT_PRIV_VIRTUAL         YES)
    set(DOXYGEN_EXTRACT_PACKAGE         YES)
    set(DOXYGEN_EXTRACT_STATIC         YES)
    set(DOXYGEN_EXTRACT_LOCAL_CLASSES         YES)
    
    set(DOXYGEN_HIDE_UNDOC_MEMBERS  NO)
    set(DOXYGEN_QUIET               NO)
    set(DOXYGEN_OUTPUT_DIRECTORY  "doc")
    set(DOXYGEN_CREATE_SUBDIRS  YES)
    set(DOXYGEN_SOURCE_BROWSER  YES)
    set(DOXYGEN_INLINE_SOURCES  YES)
    set(DOXYGEN_STRIP_CODE_COMMENTS  YES)

    set(DOXYGEN_DISABLE_INDEX  YES)
    set(DOXYGEN_GENERATE_TREEVIEW  YES)
    set(DOXYGEN_FULL_SIDEBAR  YES)
    
    
    set(DOXYGEN_DOT_UML_DETAILS  YES)
    set(DOXYGEN_UML_LOOK  YES)
    set(DOXYGEN_GROUP_GRAPH  YES)
    set(DOXYGEN_CLASS_GRAPH  YES)
    set(DOXYGEN_COLLABORATION_GRAPH  YES)
    set(DOXYGEN_CALL_GRAPH  YES)
    set(DOXYGEN_CALLER_GRAPH  YES)
    set(DOXYGEN_DIR_GRAPH_MAX_DEPTH  3)
    set(DOXYGEN_DOT_IMAGE_FORMAT  "svg")
    set(DOXYGEN_INTERACTIVE_SVG  YES)

    # Handle EXCLUDE_PATTERNS - combine default with user-provided
    set(DEFAULT_EXCLUDE_PATTERNS
        "*/build/*"
        "*/_deps/*"
        "*/cmake_scripts/*"
        "*/test*/*"
    )
    set(DOXYGEN_EXCLUDE_PATTERNS ${DEFAULT_EXCLUDE_PATTERNS} ${${PREFIX}_EXCLUDE_PATTERNS})

    # Add the custom target using doxygen_add_docs
    doxygen_add_docs("doc" # Use the parsed target name
        ${${PREFIX}_SOURCES}           # Use the parsed list of sources
        COMMENT "Generating Doxygen documentation for ${${PREFIX}_PROJECT_DISPLAY_NAME} (Target: ${${PREFIX}_NAME})"
        ${${PREFIX}_ALL}               # Pass the ALL flag if present
    )
    message(STATUS "Doxygen target '${${PREFIX}_NAME}' configured. Output will be in: ${DOXY_HTML_OUTPUT}")

endfunction()