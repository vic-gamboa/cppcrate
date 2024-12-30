#include "boost/filesystem/operations.hpp"
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace boost::filesystem;

int main(int argc, char *argv[]) {
    std::vector<std::string> directories = {"/include", "/src", "/tests"};
    std::vector<std::string> files = {"example.h", "main.cpp", "test_main.cpp",
                                      "cppcrate.toml", "Makefile"};

    if (argc < 2) {
        return 1;
    }
    if (strcmp(argv[1], "new") < 1) {
        std::cout << "I like bear" << std::endl;
        for (int i = 0; i < 3; ++i) {
            path p(argv[2]);
            path newPath = p / directories[i];
            create_directories(newPath);
            path filePath = newPath / files[i];
            std::ofstream os(filePath.string());
            path fortnite = p / files[3];
            std::ofstream crate(fortnite.string());
            path fort = p / files[4];
            std::ofstream make(fort.string());
        }

    } else {
        std::cout << "Not a valid argument" << std::endl;
    }
}
