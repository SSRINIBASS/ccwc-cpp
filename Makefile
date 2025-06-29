# Name of the executable
TARGET = ccwc

# Source files
SRC = main.cpp

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	rm -f $(TARGET)
