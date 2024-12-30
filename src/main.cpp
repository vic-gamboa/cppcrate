#include "boost/filesystem/operations.hpp"
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace boost::filesystem;

void copyTemplateFiles(const path &templatePath, const path &destinationPath) {
    std::ifstream templateFile(templatePath.string());
    if (!templateFile) {
        std::cerr << "Error: Unable to open the template file: " << templatePath
                  << std::endl;
        return;
    }

    std::ofstream destinationFile(destinationPath.string());
    if (!destinationFile) {
        std::cerr << "Error: Unable to create the destination file: "
                  << destinationPath << std::endl;
        return;
    }
    std::string line;

    while (std::getline(templateFile, line)) {
        destinationFile << line << std::endl;
    }

    std::cout << "Destination file created: " << destinationPath << std::endl;
}

void initializeProjectFiles(const path &projectPath,
                            const std::vector<std::string> &directories,
                            const std::vector<std::string> &files) {
    for (size_t i = 0; i < directories.size(); ++i) {
        path dirPath = projectPath / directories[i];
        create_directories(dirPath);

        path templatePath = "./templates/" + files[i];
        path filePath = dirPath / files[i];
        copyTemplateFiles(templatePath, filePath);
    }

    std::vector<std::string> globalFiles = {"cppcrate.toml", "Makefile"};
    for (auto const &globalFile : globalFiles) {
        path templatePath = "./templates/" + globalFile;
        path filePath = projectPath / globalFile;
        copyTemplateFiles(templatePath, filePath);
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::string> directories = {"/include", "/src", "/tests"};
    std::vector<std::string> files = {"example.h", "main.cpp", "test_main.cpp"};

    if (argc < 3) {
        std::cerr << "Usage: cppcrate new <projectname>" << std::endl;
        return 1;
    }

    if (std::string(argv[1]) == "new") {
        path projectPath(argv[2]);
        std::cout << "Initializing new project: " << projectPath << std::endl;
        initializeProjectFiles(projectPath, directories, files);
    } else {
        std::cerr << "Error: Invalid Command. Use 'cppcrate new <projectname>'."
                  << std::endl;
        return 1;
    }
    return 0;
}
