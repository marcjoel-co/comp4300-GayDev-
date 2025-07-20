# Makefile for Project FarmGuard - V.0.6.1

CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

# --- DIRECTORY SETUP ---
SRCDIR = src
BUILDDIR = build
LIBDIR = libs
INCDIR = include

# --- COMPILER FLAGS ---
INC_PATHS = -I$(LIBDIR)/include -I$(INCDIR)

# --- LINKER FLAGS ---
LIB_PATHS = -L$(LIBDIR)/lib
LINK_LIBS = -lSDL3 -lSDL3_image

# --- TARGETS ---
TARGET = $(BUILDDIR)/FarmGuard.exe
# This automatically finds ALL .cpp files in src/
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# This converts them to .o files in build/
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# --- BUILD RULES ---
all: $(TARGET) copy_dll

$(TARGET): $(OBJECTS)
	@echo "Linking executable..."
	@mkdir -p $(BUILDDIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LIB_PATHS) $(LINK_LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INC_PATHS) -c $< -o $@

copy_dll: $(TARGET)
	@echo "Copying required DLLs..."
	cp $(LIBDIR)/bin/SDL3.dll $(BUILDDIR)
	cp $(LIBDIR)/bin/SDL3_image.dll $(BUILDDIR)

.PHONY: all clean run build

build: all

clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILDDIR)/*


run:
	@echo "Running game..."
	$(BUILDDIR)/$(notdir $(TARGET))