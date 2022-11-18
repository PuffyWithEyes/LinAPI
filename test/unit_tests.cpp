// INFO: Unit-Tests
#include <iostream>
#include <memory>
#include "../bin/linapi.hpp"
#include "define.hpp"
#include <fstream>
#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"


int main() {
    /* ////////////////////////////////////////////////////////////////// */

    auto testSize = linapi::Terminal::get_size_console_x();

    if (testSize > 0)  // INFO: Test 1
        std::cout << "Test 1 | " << GREEN << "Passed" << RESET << '[' << testSize << ']' << std::endl;
    else
        std::cout << "Test 1 | " << RED << "Failed" << RESET << '[' << testSize << ']' << std::endl;

    /* ////////////////////////////////////////////////////////////////// */

    testSize = linapi::Terminal::get_size_console_y();

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

    files->make_directory("test");

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

    files->make_directory("-v", "test");

    ls = files->local_search();

    if (ls == LS_TOUCH)  // INFO: Test 10
        std::cout << "Test 10 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 10 | " << RED << "Failed" << RESET << '[' << ls << ']' << std::endl;

    files->remove("-rf", "test");

    /* ////////////////////////////////////////////////////////////////// */

    std::ofstream file;
    file.open("test1");

    if (file.is_open())
        file << "Test words" << std::endl;

    file.close();

    files->copy("test1", "test2");
    ls = files->local_search();

    std::string line1, line2;
    std::ifstream in1("test1");

    if (in1.is_open())
        getline(in1, line1);

    in1.close();

    std::ifstream in2("test1");

    if (in2.is_open())
        getline(in2, line2);

    in2.close();

    if (ls == DEFAULT_COPY && line1 == "Test words" && line2 == "Test words")  // INFO: Test 11
        std::cout << "Test 11 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 11 | " << RED << "Failed" << RESET << '[' << ls << '|' << line1 << '|' << line2 << ']' <<
        std::endl;

    files->remove("test1 test2");

    /* ////////////////////////////////////////////////////////////////// */

    files->touch("test1 test2");
    files->make_directory("test");
    files->copy("-f", "test1 test2", "test");

    ls = files->local_search("test");

    if (ls == PARAM_COPY)  // INFO: Test 12
        std::cout << "Test 12 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 12 | " << RED << "Failed" << RESET << '[' << ls << ']' << std::endl;

    files->remove("-rf", "test");
    files->remove("test1 test2");

    /* ////////////////////////////////////////////////////////////////// */

    file.open("test");

    if (file.is_open())
        file << "Test words" << std::endl;

    file.close();

    auto cat = files->cat("-e", "test");

    if (cat == "Test words$")  // INFO: Test 13
        std::cout << "Test 13 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 13 | " << RED << "Failed" << RESET << '[' << cat << ']' << std::endl;

    files->remove("test");

    /* ////////////////////////////////////////////////////////////////// */

    file.open("test");

    if (file.is_open())
        file << "Test words" << std::endl;

    file.close();

    std::string more = files->more("test");

    if (more == "Test words")  // INFO: Test 14
        std::cout << "Test 14 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 14 | " << RED << "Failed" << RESET << '[' << more << ']' << std::endl;

    files->remove("test");

    /* ////////////////////////////////////////////////////////////////// */

    file.open("test");

    if (file.is_open())
        file << "Test words" << std::endl;

    file.close();

    std::string head = files->head("test");

    if (head == "Test words")  // INFO: Test 14
        std::cout << "Test 14 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 14 | " << RED << "Failed" << RESET << '[' << head << ']' << std::endl;

    files->remove("test");

    /* ////////////////////////////////////////////////////////////////// */


    file.open("test");

    if (file.is_open())
        file << "Test words" << std::endl;

    file.close();

    head = files->head("-q", "test");

    if (head == "Test words")  // INFO: Test 15
        std::cout << "Test 15 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 15 | " << RED << "Failed" << RESET << '[' << head << ']' << std::endl;

    files->remove("test");

    /* ////////////////////////////////////////////////////////////////// */

    file.open("test");

    if (file.is_open())
        file << "Test words" << std::endl;

    file.close();

    std::string tail = files->tail("test");

    if (tail == "Test words")  // INFO: Test 16
        std::cout << "Test 16 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 16 | " << RED << "Failed" << RESET << '[' << tail << ']' << std::endl;

    files->remove("test");

    /* ////////////////////////////////////////////////////////////////// */

    file.open("test");

    if (file.is_open())
        file << "Test words" << std::endl;

    file.close();

    tail = files->tail("-q", "test");

    if (tail == "Test words")  // INFO: Test 17
        std::cout << "Test 17 | " << GREEN << "Passed" << RESET << std::endl;
    else
        std::cout << "Test 17 | " << RED << "Failed" << RESET << '[' << tail << ']' << std::endl;

    files->remove("test");

    /* ////////////////////////////////////////////////////////////////// */


    return 0;
}
