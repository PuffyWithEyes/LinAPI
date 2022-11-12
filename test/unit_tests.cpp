// INFO: Unit-Tests
#include <iostream>
#include <memory>
#include "../bin/linapi.hpp"
#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"


int main() {
    /* ////////////////////////////////////////////////////////////////// */
    auto test = linapi::Console::get_size_console_x();

    if (test > 0)  // INFO: Test 1
        std::cout << "Test 1 | " << GREEN << "Passed" << RESET << '[' << test << ']' << std::endl;
    else
        std::cout << "Test 1 | " << RED << "Failed" << RESET << '[' << test<< ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    test = linapi::Console::get_size_console_y();

    if (test > 0)  // INFO: Test 2
        std::cout << "Test 2 | " << GREEN << "Passed" << RESET << '[' << test << ']' << std::endl;
    else
        std::cout << "Test 2 | " << RED << "Failed" << RESET << '[' << test << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    std::unique_ptr<linapi::Files> files(new linapi::Files);

    auto ls = files->local_search();

    if (ls == "CMakeCache.txt\n"
              "CMakeFiles\n"
              "Testing\n"
              "build.ninja\n"
              "cmake_install.cmake\n"
              "coverage\n"
              "linapi\n")  // INFO: Test 3
        std::cout << "Test 3 | " << GREEN << "Passed" << RESET << '[' << ls << ']' << std::endl;
    else
        std::cout << "Test 3 | " << RED << "Failed" << RESET << '[' << ls << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    return 0;
}
