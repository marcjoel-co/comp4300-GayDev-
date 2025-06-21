# Makefile for Project FarmGuard

# 1. Compiler and Flags
CXX = clang++
CXXFLAGS = -std=c++17 -g -Wall
# Get SDL2 flags for include paths
CXXFLAGS += $(shell sdl2-config --cflags)

# 2. Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build

# 3. Executable Name
TARGET = $(BUILDDIR)/FarmGuard

# 4. Source Files and Object Files
# Find all .cpp files in the source directory
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Replace the .cpp extension with .o and put them in the build directory
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# 5. Linker Flags
# Get SDL2 flags for library paths and linking
LDFLAGS = $(shell sdl2-config --libs)

# 6. Build Rules
# The 'all' rule is the default goal.
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Rule to compile a .cpp source file into a .o object file
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR) # Ensure build directory exists
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# 7. Phony Targets (commands that don't represent files)
.PHONY: all clean run

# Rule to clean up build artifacts
clean:
	rm -rf $(BUILDDIR)/*

# Rule to build and run the project
run: all
	./$(TARGET)