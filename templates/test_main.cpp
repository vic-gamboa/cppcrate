#include "../include/example.h"
#include <iostream>

// Basic test framework (can be replaced with something like Google Test)
int main() {
    std::cout << "Running tests..." << std::endl;

    // Example test
    Example bear;
    bear.doSomething();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
