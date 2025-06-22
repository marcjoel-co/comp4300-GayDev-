# Makefile for Project FarmGuard (Windows/MinGW with SDL3) - V.0.2.2

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
all: $(TARGET) copy_dll

$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LIB_PATHS) $(LINK_LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INC_PATHS) -c $< -o $@

copy_dll:
	cp $(LIBDIR)/bin/SDL3.dll $(BUILDDIR)

.PHONY: all clean run copy_dll

clean:
	rm -rf $(BUILDDIR)/*

# CORRECTED: Use `notdir` to get just the filename for execution.
run: all
	cd $(BUILDDIR) && ./$(notdir $(TARGET))