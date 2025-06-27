# Compiler to use
CXX = g++

# Compiler flags:
# -Wall: Enable all common warnings
# -std=c++11: Use C++11 standard
# -g: Include debugging information
# -O0: No optimization (good for development/debugging)
CXXFLAGS = -Wall -std=c++11 -g -O0
CXXFLAGS2 = -Wall -std=c++11 -g -O0 -D NDEBUG

# Name of the executable
TARGET = a.out

file1 = main
file2 = displaySeqContainer

# Object files needed for the executable
OBJECTS = $(file1).o $(file2).o

# --- Targets ---

# 1. Just build (default target if 'make' is run without arguments)
build: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to compile $(file1).cpp into $(file1).o
$(file1).o: $(file1).cpp $(file2).hpp
	$(CXX) $(CXXFLAGS) -c $(file1).cpp

# Rule to compile $(file1).cpp into $(file1).o
$(file2).o: $(file2).cpp $(file2).hpp
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

DOXYGEN_CONF_MASTER = DoxyfileMaster
DOXYGEN_CONF_LOCAL = DoxyfileLocal

# 6. copy the doxygen configuration file
doxyCopy:
	cp ../../../$(DOXYGEN_CONF_MASTER) ./$(DOXYGEN_CONF_LOCAL)
	@echo "Doxygen config file copy completed."

# 7. Start doxygen document genertion
doxygenStart:
	@echo "Doxygen started doc generation..."
	doxygen $(DOXYGEN_CONF_LOCAL)
	@echo "Doxygen finished doc generation..."

# 8. Clean documentations
cleanDoc:
	rm -rf doc $(DOXYGEN_CONF_LOCAL)

# 9. copy doxygen config file and start doc generation
doxyCS: doxyCopy doxygenStart

.PHONY: build run all clean clean_build doxyCopy doxygenStart cleanDoc