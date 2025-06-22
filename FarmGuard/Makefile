# Makefile for Project FarmGuard (Windows/MinGW with SDL3) - V.0.2.3

CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

# --- DIRECTORY SETUP ---
SRCDIR = src
BUILDDIR = build
LIBDIR = libs

# --- COMPILER FLAGS ---
INC_PATHS = -I$(LIBDIR)/include

# --- LINKER FLAGS ---
LIB_PATHS = -L$(LIBDIR)/lib
LINK_LIBS = -lSDL3

# --- TARGETS ---
TARGET = $(BUILDDIR)/FarmGuard.exe
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# --- BUILD RULES ---

# The default 'all' rule now builds the executable and copies the DLL.
all: $(TARGET) copy_dll

# The executable must be built before we can copy the DLL.
copy_dll: $(TARGET)
	@echo "Copying required DLLs..."
	cp $(LIBDIR)/bin/SDL3.dll $(BUILDDIR)

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
	cd $(BUILDDIR) && ./$(notdir $(TARGET))