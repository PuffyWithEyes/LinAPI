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

    auto testSize = linapi::Console::get_size_console_x();

    if (testSize > 0)  // INFO: Test 1
        std::cout << "Test 1 | " << GREEN << "Passed" << RESET << '[' << testSize << ']' << std::endl;
    else
        std::cout << "Test 1 | " << RED << "Failed" << RESET << '[' << testSize << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    testSize = linapi::Console::get_size_console_y();

    if (testSize > 0)  // INFO: Test 2
        std::cout << "Test 2 | " << GREEN << "Passed" << RESET << '[' << testSize << ']' << std::endl;
    else
        std::cout << "Test 2 | " << RED << "Failed" << RESET << '[' << testSize << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    std::unique_ptr<linapi::Files> files(new linapi::Files);

    auto ls = files->local_search();
    auto lsOption = files->local_search("-r");
    auto lsPath = files->local_search(TEST_PATH);
    auto lsOptionPath = files->local_search("-r", TEST_PATH);

    if (ls == PATH_LS && lsOption == RPATH_LS && lsPath == LS_TEST_PATH && lsOptionPath == RLS_TEST_PATH)  // INFO: Test 3
        std::cout << "Test 3 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 3 | " << RED << "Failed" << RESET << '[' << ls << '|' << lsOption << '|' << lsPath << '|' <<
        lsOptionPath << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    auto pwd = files->path_to_directory();
    auto pwdOption = files->path_to_directory("-P");

    if (pwd == THIS_PATH && pwdOption == THIS_PATH)  // INFO: Test 4
        std::cout << "Test 4 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 4 | " << RED << "Failed" << RESET << '[' << pwd << '|' << pwdOption << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    files->touch("test");

    ls = files->local_search();

    if (ls == LS_TOUCH)  // INFO: Test 5
        std::cout << "Test 5 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 5 | " << RED << "Failed" << RESET << '[' << ls << '|' << pwdOption << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    files->remove("test");

    ls = files->local_search();

    if (ls == PATH_LS)  // INFO: Test 6
        std::cout << "Test 6 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 6 | " << RED << "Failed" << RESET << '[' << ls << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    files->touch("-a", "test");

    ls = files->local_search();

    if (ls == LS_TOUCH)  // INFO: Test 7
        std::cout << "Test 7 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 7 | " << RED << "Failed" << RESET << '[' << ls << ']' << std::endl;

    files->remove("test");

    /* ////////////////////////////////////////////////////////////////// */

    files->mkdir("test");

    ls = files->local_search();

    if (ls == LS_TOUCH)  // INFO: Test 8
        std::cout << "Test 8 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 8 | " << RED << "Failed" << RESET << '[' << ls << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    files->remove("-rf", "test");

    ls = files->local_search();

    if (ls == PATH_LS)  // INFO: Test 9
        std::cout << "Test 9 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 9 | " << RED << "Failed" << RESET << '[' << ls << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    files->mkdir("-v", "test");

    ls = files->local_search();

    if (ls == LS_TOUCH)  // INFO: Test 10
        std::cout << "Test 10 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 10 | " << RED << "Failed" << RESET << '[' << ls << ']' << std::endl;

    files->remove("-rf", "test");

    /* ////////////////////////////////////////////////////////////////// */

    return 0;
}
