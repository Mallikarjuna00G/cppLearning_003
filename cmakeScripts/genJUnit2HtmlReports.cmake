# ====== START: Test Report Generation =====
# Find the python3 interpreter
find_program(PYTHON_EXECUTABLE python3)
if(NOT PYTHON_EXECUTABLE)
    message(FATAL_ERROR "Python 3 executable not found.")
endif()

set(PY_VENV_NAME "py_venv")
# set(PY_VENV_DIR "${REPO_LOC}${PY_VENV_NAME}")
set(PY_VENV_DIR "$ENV{HOME}/${PY_VENV_NAME}")

set(PY_MODULE "junit2html")
# We will use this variable to store the path to the junit2html executable
set(JUNIT2HTML_EXECUTABLE "${PY_VENV_DIR}/bin/${PY_MODULE}")
set(REPORTS_DIR "${CMAKE_BINARY_DIR}/Testing/Reports")

set(FILENAME_TO_COPY "gen_junit2html_reports.sh")
file(COPY_FILE ${REPO_LOC_OTHER_SCRIPTS}/${FILENAME_TO_COPY} ${CMAKE_BINARY_DIR}/${FILENAME_TO_COPY})


# Create a master target that depends on all the individual HTML reports.
# This makes it easy to generate all of them by building this single target.
add_custom_target(
    junit2html_reports
    # This is the command that will be executed when you build this target.
    # It calls a shell to run the bash script located in the binary directory.
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR} bash "${CMAKE_BINARY_DIR}/${FILENAME_TO_COPY}"

    COMMENT "Running bash script to generate combined JUnit HTML report."
)

# ====== END: Test Report Generation =====