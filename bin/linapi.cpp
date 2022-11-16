#include "linapi.hpp"
#include <fstream>
#include <iostream>
#include <memory>


std::string linapi::API::get_answer_terminal(const char *command) {
    char buffer[4096];
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command, "r"), pclose);

    if (!pipe)
        throw std::runtime_error("popen() failed!");

    while (fgets(buffer, 4096, pipe.get()) != nullptr)
        result += buffer;

    return result;
}


unsigned linapi::Console::get_size_console_x() { return std::stoul(API::get_answer_terminal("tput cols")); }


unsigned linapi::Console::get_size_console_y() { return std::stoul(API::get_answer_terminal("tput lines")); }


std::string linapi::Files::local_search() { return API::get_answer_terminal("ls"); }


std::string linapi::Files::local_search(const char *optionOrPath) {
    std::string ls = "ls ", command = ls + optionOrPath;

    return API::get_answer_terminal(command.c_str());
}


std::string linapi::Files::local_search(const char *option, const char *path) {
    std::string ls = "ls ", command = ls + option + ' ' + path;

    return API::get_answer_terminal(command.c_str());
}
