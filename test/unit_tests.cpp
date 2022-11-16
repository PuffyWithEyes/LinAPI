// INFO: Unit-Tests
#include <iostream>
#include <memory>
#include "../bin/linapi.hpp"
#include "define.hpp"
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
    auto lsOption = files->local_search("-r");
    auto lsPath = files->local_search(TEST_PATH);
    auto lsOptionPath = files->local_search("-r", TEST_PATH);

    std::cout << lsPath << std::endl;

    if (ls == PATH_LS && lsOption == RPATH_LS && lsPath == LS_TEST_PATH && lsOptionPath == RLS_TEST_PATH)  // INFO: Test 3
        std::cout << "Test 3 | " << GREEN << "Passed" << RESET << '[' << ls << '|' << lsOption << '|' << lsPath << '|' << lsOptionPath << ']' << std::endl;
    else
        std::cout << "Test 3 | " << RED << "Failed" << RESET << '[' << ls << '|' << lsOption << '|' << lsPath << '|' << lsOptionPath << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    return 0;
}
