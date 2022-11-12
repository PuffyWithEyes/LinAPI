#include <iostream>
#include "../bin/linapi.hpp"
#include <memory>


void test_memory() {
    unsigned counter = 0;
    bool answer;

    std::cout << "Test 1" << std::endl;
    while (true) {
        if (counter != 500) {
            linapi::Console::get_size_console_x();

            counter++;
        } else {
            std::cout << "Continue?: "; std::cin >> answer;
            if (answer)
                counter = 0;
            else
                break;
        }
    }

    counter = 0;

    std::cout << "Test 2" << std::endl;
    while (true) {
        if (counter != 500) {
            linapi::Console::get_size_console_y();

            counter++;
        } else {
            std::cout << "Continue?: "; std::cin >> answer;
            if (answer)
                counter = 0;
            else
                break;
        }
    }

    counter = 0;

    std::cout << "Test 3" << std::endl;
    while (true) {
        if (counter != 500) {
            linapi::Files::local_search();

            counter++;
        } else {
            std::cout << "Continue?: "; std::cin >> answer;
            if (answer)
                counter = 0;
            else
                break;
        }
    }
}

