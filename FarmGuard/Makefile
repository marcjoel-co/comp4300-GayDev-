# Makefile for Project FarmGuard (Windows/MinGW with SDL3) - V.0.2.4

CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

# --- DIRECTORY SETUP ---
SRCDIR = src
BUILDDIR = build
LIBDIR = libs

# --- COMPILER FLAGS ---
# Add include path for your own headers
INC_PATHS = -I$(LIBDIR)/include -Iinclude

# --- LINKER FLAGS ---
LIB_PATHS = -L$(LIBDIR)/lib
LINK_LIBS = -lSDL3 -lSDL3_image

# --- TARGETS ---
TARGET = $(BUILDDIR)/FarmGuard.exe

# Explicitly list source files to ensure keyEvents.cpp is included
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/keyEvents.cpp
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# --- BUILD RULES ---

# The default 'all' rule now builds the executable and copies the DLL.
all: $(TARGET) copy_dll

# The executable must be built before we can copy the DLL.
copy_dll: $(TARGET)
	@echo "Copying required DLLs..."
	cp $(LIBDIR)/bin/SDL3.dll $(BUILDDIR)
	cp $(LIBDIR)/bin/SDL3_image.dll $(BUILDDIR)

$(TARGET): $(OBJECTS)
	@echo "Linking executable..."
	@mkdir -p $(BUILDDIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LIB_PATHS) $(LINK_LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INC_PATHS) -c $< -o $@

# --- UTILITY RULES ---
.PHONY: all clean run build

# A new explicit 'build' rule for clarity.
build: all

clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILDDIR)/*

# The 'run' rule NO LONGER builds. It only executes the existing file.
run:
	@echo "Running game..."
	$(BUILDDIR)/$(notdir $(TARGET))

# Optional: Add a debug rule that shows the working directory
debug:
	@echo "Running game in debug mode..."
	@echo "Working directory: $$(pwd)"
	$(BUILDDIR)/$(notdir $(TARGET))