# --- PlantUML ---
# Define the required version and the location of the plantuml.jar file.
set(PLANTUML_REQUIRED_VERSION "1.2025.4")
set(PLANTUML_JAR_LOCATION "/usr/local/bin/plantuml.jar" CACHE FILEPATH "Path to plantuml.jar")

# 1. Check if the plantuml.jar file exists
if(NOT EXISTS "${PLANTUML_JAR_LOCATION}")
    message(FATAL_ERROR "PlantUML JAR not found at ${PLANTUML_JAR_LOCATION}. "
                        "Please set PLANTUML_JAR_LOCATION to the correct path.")
endif()

include(${REPO_LOC_CMAKE_SCRIPTS}/checkForJava.cmake)

# 3. Execute PlantUML to get its version string
execute_process(
    COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${PLANTUML_JAR_LOCATION}" -version
    RESULT_VARIABLE PLANTUML_RESULT
    OUTPUT_VARIABLE PLANTUML_VERSION_OUTPUT
    ERROR_VARIABLE PLANTUML_ERROR_OUTPUT
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# 4. Check if the command succeeded and parse the version
if(PLANTUML_RESULT EQUAL 0)
    string(REGEX MATCH "PlantUML version ([.0-9]+)" _ "${PLANTUML_VERSION_OUTPUT}")
    set(PLANTUML_VERSION_FOUND "${CMAKE_MATCH_1}")

    if(NOT PLANTUML_VERSION_FOUND)
        message(FATAL_ERROR "Could not parse PlantUML version from output:\n${PLANTUML_VERSION_OUTPUT}")
    endif()

    # 5. Compare the found version with the required version
    if(PLANTUML_VERSION_FOUND VERSION_LESS "${PLANTUML_REQUIRED_VERSION}")
        message(FATAL_ERROR "PlantUML version check failed. Found ${PLANTUML_VERSION_FOUND}, but require ${PLANTUML_REQUIRED_VERSION} or newer.")
    else()
        message(STATUS "Found PlantUML: ${PLANTUML_JAR_LOCATION} (version ${PLANTUML_VERSION_FOUND})")
    endif()
else()
    message(FATAL_ERROR "Failed to execute PlantUML to get version.\n"
                        "Command: ${Java_JAVA_EXECUTABLE} -jar ${PLANTUML_JAR_LOCATION} -version\n"
                        "Error: ${PLANTUML_ERROR_OUTPUT}")
endif()
