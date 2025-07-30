# CMakeLists.txt for your project

# 1. Minimum CMake version required
#    Always specify a recent enough version. 3.10 is a good baseline for modern CMake features.
cmake_minimum_required(VERSION 3.10)

# 2. Project definition
#    Sets the project name and specifies the language(s) used.
project(checkDoxy LANGUAGES CXX VERSION 1.0)

# 3. Set C++ Standard
#    It's good practice to explicitly define the C++ standard your project uses.
#    C++17 is common now, but you can change it to 11, 14, or 20.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Ensure the compiler enforces this standard
set(CMAKE_CXX_EXTENSIONS OFF)      # Don't use compiler-specific extensions


# Optional: Set common build types if not using a multi-config generator (like VS Code/Ninja)
# If you are configuring with `cmake -DCMAKE_BUILD_TYPE=Debug ..` etc.
# These will apply default flags for Debug, Release etc.
# For example, adding a simple common compile option
add_compile_options(-Wall -Wextra -pedantic) # Good for warnings

# 4. Define the executable target
#    We create an executable named '${PROJECT_NAME}'.
#    List all the .cpp source files that belong to this executable.
#    CMake automatically finds associated header files if they are in include paths.
add_executable(${PROJECT_NAME}
    main.cpp
    displaySeqContainer.cpp
    support_forwardList.cpp
    support_list.cpp
    support_vector.cpp
)

# 5. Specify include directories
#    Since all your .hpp files are in the same directory as your .cpp files,
#    we just need to add the current source directory to the include paths.
#    'PRIVATE' means these include directories are only needed for compiling this target itself.
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)


# ====== START: For DOXYGEN Documentation =====

# Include custom CMake script for Doxygen documentation generation
include(../../../DoxygenDoc.cmake)

# Call the function defined in DoxygenDoc.cmake to add our project's documentation target
# Using named arguments makes the call much clearer.
add_my_doxygen_target(
    PREFIX "MY_SIMPLE_DEBUG_PREFIX"
    PRJ_NAME "${PROJECT_NAME}"
    SOURCES "${PROJECT_SOURCE_DIR}"
    PRJ_BRIEF ""
    )


# ====== END: For DOXYGEN Documentation =====