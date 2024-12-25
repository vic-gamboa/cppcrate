#include "boost/filesystem/operations.hpp"
#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>

using namespace boost::filesystem;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        return 1;
    }

    path p(argv[1]);

    if (is_directory(p)) {
        std::cout << p << " is a directory containing: " << std::endl;
        std::vector<path> paths;
        for (auto &&x : directory_iterator(p))
            paths.push_back(x.path());
        std::sort(paths.begin(), paths.end());

        for (auto &&x : paths) {
            std::cout << "      " << x.filename() << std::endl;
        }
    } else {
        std::cout << p << " is not a directory" << std::endl;
    }
}
