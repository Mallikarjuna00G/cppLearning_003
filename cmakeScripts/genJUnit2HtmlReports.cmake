# ====== START: Test Report Generation =====
# Find the python3 interpreter
find_program(PYTHON_EXECUTABLE python3)
if(NOT PYTHON_EXECUTABLE)
    message(FATAL_ERROR "Python 3 executable not found.")
endif()

set(PY_VENV_NAME "py_venv")
set(VENV_DIR "${REPO_LOC}${PY_VENV_NAME}")

set(PY_MODULE "junit2html")
# We will use this variable to store the path to the junit2html executable
set(JUNIT2HTML_EXECUTABLE "${VENV_DIR}/bin/${PY_MODULE}")
set(REPORTS_DIR "${CMAKE_BINARY_DIR}/Testing/Reports")
# The custom target will check for the executable's existence and install if needed.
add_custom_target(
    combined_junit_report
    COMMAND ${CMAKE_COMMAND} -E make_directory "${REPORTS_DIR}/combined_junit_report"
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR} ${JUNIT2HTML_EXECUTABLE} "${REPORTS_DIR}/*.xml" "${REPORTS_DIR}/combined_junit_report/combined_junit_report.html"

    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Automating the setup and generation of a combined JUnit HTML report."

    # Add a dependency to ensure the tests have run and the XML files exist
    # DEPENDS your_test_suite_executable_name
)

# ====== END: Test Report Generation =====