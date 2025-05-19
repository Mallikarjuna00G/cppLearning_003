#!/bin/bash

# Script name: perform.sh

# SOURCE_FILE="$1"
SOURCE_FILE="ch01_exrc_1p25.cpp"
# EXECUTABLE_NAME="${SOURCE_FILE%.cpp}" # Remove .cpp extension for executable name
EXECUTABLE_NAME="a.out" # Remove .cpp extension for executable name

usage() {
  echo "Usage: $0 <cpp_source_file> [option]"
  echo "Options:"
  echo "  1   Compile the C++ source file using g++ with C++11 standard."
  echo "  2   Execute the compiled program."
  echo "  3   Remove the compiled executable file."
  echo "If no option is provided, it defaults to 'compile'."
}

if [ -z "$SOURCE_FILE" ]; then
  usage
  exit 1
fi

if [ ! -f "$SOURCE_FILE" ]; then
  echo "Error: Source file '$SOURCE_FILE' not found."
  exit 1
fi

compile_program() {
  echo "Compiling '$SOURCE_FILE' using g++ with C++11 standard..."
  COMMAND="g++ -std=c++11 -Wall $SOURCE_FILE -o $EXECUTABLE_NAME"
  echo $COMMAND
  $COMMAND
  if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
  fi
  echo "Compilation successful. Executable created: '$EXECUTABLE_NAME'"
}

execute_program() {
  if [ ! -f "$EXECUTABLE_NAME" ]; then
    echo "NOTE: Please compile the program first"
    echo "----------------------"
    usage
    exit 1
  fi
  echo "Executing './$EXECUTABLE_NAME'..."
  ./"$EXECUTABLE_NAME"

  echo -e "\n--------------------------\nLast execution status: $(echo $?)"
}

clear_files() {
  if [ -f "$EXECUTABLE_NAME" ]; then
    echo "Removing executable file: '$EXECUTABLE_NAME'"
    rm "$EXECUTABLE_NAME"
  else
    echo "Executable file '$EXECUTABLE_NAME' not found."
  fi
}

# OPTION="$2"
OPTION="$1"

case "$OPTION" in
  "1")
    compile_program
    ;;
  "2")
    execute_program
    ;;
  "3")
    clear_files
    ;;
  "")
    compile_program # Default option if none is provided
    ;;
  *)
    echo "Error: Invalid option '$OPTION'."
    usage
    exit 1
    ;;
esac

exit 0