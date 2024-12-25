# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lboost_filesystem -lboost_system

# Target and source
TARGET = main
SRC = src/main.cpp

# Build the target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Clean up
clean:
	rm -f $(TARGET)

