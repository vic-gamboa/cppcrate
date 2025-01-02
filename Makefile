# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lboost_filesystem -lboost_system

# Target and source
TARGET = cppcrate
SRC = src/main.cpp

# Default target: Build and install
all: $(TARGET)

# Build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Install the executable globally to /usr/local/bin
install: $(TARGET)
	@echo "Installing $(TARGET) to /usr/local/bin..."
	@sudo cp $(TARGET) /usr/local/bin/
	@echo "Installation complete. You can now run $(TARGET) globally."

# Uninstall the executable
uninstall:
	@echo "Removing $(TARGET) from /usr/local/bin..."
	@sudo rm -f /usr/local/bin/$(TARGET)
	@echo "Uninstallation complete."

# Clean up the local build
clean:
	rm -f $(TARGET)
	@echo "Cleaned up build files."

