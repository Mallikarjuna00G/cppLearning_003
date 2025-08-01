#!/bin/bash

VENV_DIR="py_venv"

# --- Step 1: Install the venv package if it's not present ---
# This check is for Debian/Ubuntu systems
if ! dpkg -s python3-venv >/dev/null 2>&1; then
    echo "Installing python3-venv package..."
    sudo apt update
    sudo apt install -y python3-venv
else
    echo "python3-venv package already installed."
fi

# --- Step 2: Create the virtual environment if it doesn't exist ---
if [ ! -d "${VENV_DIR}" ]; then
    echo "Creating virtual environment at ./${VENV_DIR}..."
    python3 -m venv "${VENV_DIR}"
else
    echo "Virtual environment already exists at ./${VENV_DIR}."
fi

# --- Step 3: Check for and install junit2html if it's missing ---
JUNIT2HTML_EXECUTABLE="${VENV_DIR}/bin/junit2html"
if [ ! -x "${JUNIT2HTML_EXECUTABLE}" ]; then
    echo "junit2html not found. Installing now..."
    "${VENV_DIR}/bin/python" -m pip install junit2html
else
    echo "junit2html already installed."
fi

echo "Setup complete. You can now activate the environment with: source ${VENV_DIR}/bin/activate"