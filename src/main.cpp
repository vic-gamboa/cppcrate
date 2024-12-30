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
            path template_path = "./templates/" + files[i];
            path p(argv[2]);
            path newPath = p / directories[i];
            create_directories(newPath);
            path filePath = newPath / files[i];
            std::ofstream os(filePath.string());
            path toml_path = p / files[3];
            path toml_template_path = "./templates/" + files[3];
            std::ofstream crate(toml_path.string());
            std::cout << toml_path.string() << std::endl;
            path makefile_path = p / files[4];
            path makefile_template_path = "./templates/" + files[4];
            std::ofstream make(makefile_path.string());
            std::ifstream template_file(template_path.string());
            if (!template_file) {
                std::cerr << "Error: Unable to open the file: "
                          << template_path.string() << std::endl;
                return 1;
            }
            std::ofstream new_file(filePath.string());
            std::cout << filePath.string() << std::endl;
            std::string line;
            while (std::getline(template_file, line)) {
                std::cout << "Writing: " << line << std::endl;
                new_file << line << std::endl;
            }
            std::ifstream toml_template(toml_template_path.string());
            std::ofstream new_toml(toml_path.string());
            while (std::getline(toml_template, line)) {
                new_toml << line << std::endl;
            }
            std::ifstream makefile_template(makefile_template_path.string());
            std::ofstream new_makefile(makefile_path.string());
            while (std::getline(makefile_template, line)) {
                new_makefile << line << std::endl;
            }
        }

    } else {
        std::cout << "Not a valid argument" << std::endl;
    }
}
