// INFO: Unit-Tests
#include "../bin/linapi.hpp"
#include <iostream>
#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"


int main() {
    if (*linapi::Console::_get_size_console_x() >= 0)  // INFO: Test 1
        std::cout << "Test 1 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 1 | " << RED << "Failed" << RESET << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    if (linapi::Console::get_size_console_x() >= 0)  // INFO: Test 2
        std::cout << "Test 2 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 2 | " << RED << "Failed" << RESET << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    if (*linapi::Console::_get_size_console_y() >= 0)  // INFO: Test 3
        std::cout << "Test 3 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 3 | " << RED << "Failed" << RESET << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    if (linapi::Console::get_size_console_y() >= 0)  // INFO: Test 4
        std::cout << "Test 4 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 4 | " << RED << "Failed" << RESET << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    linapi::Files files;

    unsigned size = files.get_ls_size_for_array();
    auto array = new std::string[size];

    array = files._local_search();

    if (!array[0].empty())  // INFO: Test 5
        std::cout << "Test 5 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 5 | " << RED << "Failed" << RESET << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    if (*files._get_ls_size_for_array() >= 0 && *files._get_ls_size_for_array() == files.get_ls_size_for_array())  // INFO: Test 6
        std::cout << "Test 6 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 6 | " << RED << "Failed" << RESET << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    return 0;
}
