# Compiler and Flags
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Directories
SRCDIRS  = src implement
# Find all .cpp files in both src and implement
SOURCES  = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))
# Convert .cpp paths to .o paths
OBJECTS  = $(SOURCES:.cpp=.o)
TARGET   = COMFORT

# Default target
all: $(TARGET)

# Linking: Combines all object files into the final executable
$(TARGET): $(OBJECTS)
	 $(CXX) $(OBJECTS) -o $(TARGET)

# Compilation: turn any .cpp in any dir into a .o in that same dir
%.o: %.cpp
	 $(CXX) $(CXXFLAGS) -c $< -o $@

# Run command
run: $(TARGET)
	 ./$(TARGET)

# Clean command
clean:
	 rm -f $(foreach dir,$(SRCDIRS),$(dir)/*.o) $(TARGET)