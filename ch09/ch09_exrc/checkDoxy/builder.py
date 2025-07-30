import os
import subprocess
import shutil
import argparse
import sys

# --- Configuration ---
# Assuming the script is in the root of your project
PROJECT_ROOT = os.path.dirname(os.path.abspath(__file__))
BUILD_DIR_NAME = "build"
DEFAULT_BUILD_TYPE = "Debug" # Or "Release", "RelWithDebInfo", "MinSizeRel"

# Adjust these based on your CMakeLists.txt and project structure
# Name of the main executable target (as defined by add_executable in CMakeLists.txt)
MAIN_APP_TARGET_NAME = "checkDoxy" 
# Name of the Doxygen target (e.g., as defined by add_my_doxygen_target in CMakeLists.txt)
DOXYGEN_TARGET_NAME = "doc"

# --- Utility Functions ---

def run_command(cmd, cwd=PROJECT_ROOT, check=True):
    """Runs a shell command and prints its output. Exits if command fails."""
    print(f"\nRunning command: {' '.join(cmd)}")
    try:
        result = subprocess.run(cmd, cwd=cwd, check=check, text=True, capture_output=True)
        print(result.stdout)
        if result.stderr:
            print(result.stderr, file=sys.stderr)
        return result
    except subprocess.CalledProcessError as e:
        print(f"Command failed with exit code {e.returncode}", file=sys.stderr)
        print(f"STDOUT:\n{e.stdout}", file=sys.stderr)
        print(f"STDERR:\n{e.stderr}", file=sys.stderr)
        sys.exit(e.returncode)
    except FileNotFoundError:
        print(f"Error: Command not found. Make sure '{cmd[0]}' is in your PATH.", file=sys.stderr)
        sys.exit(1)

def get_build_path():
    return os.path.join(PROJECT_ROOT, BUILD_DIR_NAME)

# --- CMake Workflow Functions ---

def clean_project(build_path):
    """Removes the build directory."""
    print(f"--- Cleaning project: Removing '{build_path}' ---")
    if os.path.exists(build_path):
        try:
            shutil.rmtree(build_path)
            print("Build directory removed successfully.")
        except Exception as e:
            print(f"Error removing build directory: {e}", file=sys.stderr)
            sys.exit(1)
    else:
        print("Build directory does not exist, nothing to clean.")

def configure_project(build_path, build_type):
    """Configures the CMake project."""
    print(f"--- Configuring project for {build_type} ---")
    os.makedirs(build_path, exist_ok=True) # Ensure build directory exists

    cmake_cmd = [
        "cmake",
        "-S", PROJECT_ROOT,
        "-B", build_path,
        f"-DCMAKE_BUILD_TYPE={build_type}"
        # Add other common CMake configure options here if needed, e.g.:
        # "-G", "Ninja"
        # "-DCMAKE_INSTALL_PREFIX=/path/to/install"
    ]
    run_command(cmake_cmd)
    print("Project configured successfully.")

def build_project(build_path, build_type):
    """Builds the CMake project."""
    print(f"--- Building project for {build_type} ---")
    # Determine optimal jobs for parallel compilation
    import multiprocessing
    num_cores = multiprocessing.cpu_count()

    cmake_build_cmd = [
        "cmake",
        "--build", build_path,
        "--config", build_type,
        "-j", str(num_cores) # Use all available cores
    ]
    run_command(cmake_build_cmd)
    print("Project built successfully.")

def launch_application(build_path, build_type, app_target_name):
    """Launches the main application."""
    print(f"--- Launching '{app_target_name}' ---")
    
    # Common convention: executables in build_path/bin/build_type/ (Windows) or build_path/ (Linux/macOS)
    if sys.platform == "win32":
        # Windows often places executables in build_path/Debug/ or build_path/Release/
        # or build_path/bin/Debug/ etc.
        # Adjust this path based on your CMAKE_RUNTIME_OUTPUT_DIRECTORY
        app_exe_path = os.path.join(build_path, build_type, f"{app_target_name}.exe")
        if not os.path.exists(app_exe_path):
             # Try common alternative: build_path/bin/Debug/
            app_exe_path = os.path.join(build_path, "bin", build_type, f"{app_target_name}.exe")
    else:
        app_exe_path = os.path.join(build_path, app_target_name) # For Linux/macOS, often directly in build_path
        if not os.path.exists(app_exe_path):
            # Try common alternative: build_path/bin/
            app_exe_path = os.path.join(build_path, "bin", app_target_name)


    if not os.path.exists(app_exe_path):
        print(f"Error: Executable not found at '{app_exe_path}'. Make sure you've built the project and defined CMAKE_RUNTIME_OUTPUT_DIRECTORY correctly.", file=sys.stderr)
        sys.exit(1)

    print(f"Executing: {app_exe_path}")
    # Using subprocess.run directly here, as output needs to go to console for interactive apps
    try:
        subprocess.run([app_exe_path], cwd=os.path.dirname(app_exe_path))
    except Exception as e:
        print(f"Error launching application: {e}", file=sys.stderr)
        sys.exit(1)


def generate_documentation(build_path, docs_target_name):
    """Generates documentation via CMake target."""
    print("--- Generating Documentation ---")
    cmake_build_docs_cmd = [
        "cmake",
        "--build", build_path,
        "--target", docs_target_name
    ]
    run_command(cmake_build_docs_cmd)
    print("Documentation generation command issued.")
    print(f"Check your Doxygen output directory, usually something like '{build_path}/docs/html/index.html'")


# --- Main Script Logic ---
if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="CMake project build orchestration script.",
        formatter_class=argparse.RawTextHelpFormatter
    )
    parser.add_argument(
        "-t", "--type",
        choices=["Debug", "Release", "RelWithDebInfo", "MinSizeRel"],
        default=DEFAULT_BUILD_TYPE,
        help=f"Set the CMake build type (default: {DEFAULT_BUILD_TYPE})."
    )
    parser.add_argument(
        "--clean",
        action="store_true",
        help="Remove the build directory before other operations."
    )
    parser.add_argument(
        "--configure",
        action="store_true",
        help="Configure the project using CMake."
    )
    parser.add_argument(
        "--build",
        action="store_true",
        help="Build the project."
    )
    parser.add_argument(
        "--launch",
        action="store_true",
        help=f"Launch the main application ({MAIN_APP_TARGET_NAME})."
    )
    parser.add_argument(
        "--docs",
        action="store_true",
        help=f"Generate documentation using the CMake target '{DOXYGEN_TARGET_NAME}'."
    )
    parser.add_argument(
        "--all",
        action="store_true",
        help="Perform clean, configure, build, and launch (in that order)."
    )

    args = parser.parse_args()

    build_path = get_build_path()

    if args.all:
        args.clean = True
        args.configure = True
        args.build = True
        args.launch = True # Automatically launch if --all is used

    # Perform actions in order
    if args.clean:
        clean_project(build_path)
    
    # Configure and Build only if requested or as part of --all
    # and if the build directory doesn't exist (unless --clean was used)
    should_configure = args.configure or (args.build and not os.path.exists(os.path.join(build_path, "CMakeCache.txt")))
    if should_configure:
        configure_project(build_path, args.type)

    if args.build:
        build_project(build_path, args.type)
    
    if args.launch:
        launch_application(build_path, args.type, MAIN_APP_TARGET_NAME)

    if args.docs:
        generate_documentation(build_path, DOXYGEN_TARGET_NAME)

    if not any([args.clean, args.configure, args.build, args.launch, args.docs, args.all]):
        print("No actions specified. Use --help for options.")

    print("\nScript execution finished.")