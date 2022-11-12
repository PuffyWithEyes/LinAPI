#include "linapi.hpp"
#include <fstream>
#include <iostream>
#include <memory>


std::string linapi::API::get_answer_terminal_pop(const char *command) {
    char buffer[4096];
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command, "r"), pclose);

    if (!pipe)
        throw std::runtime_error("popen() failed!");

    while (fgets(buffer, 4096, pipe.get()) != nullptr)
        result += buffer;

    return result;
}


unsigned linapi::Console::get_size_console_x() { return std::stoul(API::get_answer_terminal_pop("echo \"$COLUMNS\"")); }  // FIXME: Без дебаггера получаем nullptr значение


unsigned linapi::Console::get_size_console_y() { return std::stoul(API::get_answer_terminal_pop("echo \"$LINES\"")); }  // FIXME: Без дебаггера получаем nullptr значение


std::string linapi::Files::local_search() { return API::get_answer_terminal_pop("ls"); }  // FIXME: Без дебаггера получаем nullptr
