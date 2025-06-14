# Compiler to use
CXX = g++

# Compiler flags:
# -Wall: Enable all common warnings
# -std=c++11: Use C++11 standard
# -g: Include debugging information
# -O0: No optimization (good for development/debugging)
CXXFLAGS = -Wall -std=c++11 -g -O0

# Name of the executable
TARGET = a.out

file1 = ch06_exrc_6p11
file2 = reset

# Object files needed for the executable
OBJECTS = $(file1).o $(file2).o

# --- Targets ---

# 1. Just build (default target if 'make' is run without arguments)
build: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to compile $(file1).cpp into $(file1).o
$(file1).o: $(file1).cpp $(file2).h
	$(CXX) $(CXXFLAGS) -c $(file1).cpp

# Rule to compile $(file2).cpp into $(file2).o
$(file2).o: $(file2).cpp $(file2).h
	$(CXX) $(CXXFLAGS) -c $(file2).cpp

# 2. Just run the executable
run: $(TARGET)
	./$(TARGET)

# 3. Build and run (convenience target)
all: build run

# 4. Just clean (remove generated files)
clean:
	rm -f $(OBJECTS) $(TARGET)

# 5. Clean and then build
clean_build: clean build

.PHONY: build run all clean clean_build