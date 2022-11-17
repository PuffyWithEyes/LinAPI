#include "linapi.hpp"
#include <fstream>
#include <iostream>
#include <memory>


void linapi::API::split_last_char(std::string &str) { str.erase(str.size() - 1); }


std::string linapi::API::make_command(const char *command, const char *optionOrSth) {
    std::string returnedCommand = command;
    returnedCommand += ' ', returnedCommand += optionOrSth;

    return returnedCommand;
}


std::string linapi::API::make_command(const char *command, const char *option, const char *sth) {
    std::string returnedCommand = command;
    returnedCommand += ' ', returnedCommand += option, returnedCommand += ' ', returnedCommand += sth;

    return returnedCommand;
}


std::string linapi::API::make_command(const char *command, const char *option, const char *sth2, const char *sth3) {
    std::string returnedCommand = command;
    returnedCommand += ' ', returnedCommand += option, returnedCommand += ' ', returnedCommand += sth2, returnedCommand += sth3;

    return returnedCommand;
}


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


std::string linapi::Files::make_long_command(char **array, const unsigned &size) {
    std::string command;

    for (unsigned i = 0; i < size; i++) {
        command += array[i];
        command += ' ';
    }

    command += '\b';

    return command;
}


std::string linapi::Files::local_search() {
    std::string command = API::get_answer_terminal("ls");

    API::split_last_char(command);

    return command;
}


std::string linapi::Files::local_search(const char *optionOrPath) {
    std::string command = API::get_answer_terminal(API::make_command("ls", optionOrPath).c_str());
    API::split_last_char(command);

    return command;
}


std::string linapi::Files::local_search(const char *option, const char *path) {
    std::string command = API::get_answer_terminal(API::make_command("ls", option, path).c_str());
    API::split_last_char(command);

    return command;
}


std::string linapi::Files::path_to_directory() {
    std::string command = API::get_answer_terminal("pwd");

    API::split_last_char(command);

    return command;
}


std::string linapi::Files::path_to_directory(const char *option) {
    std::string command = API::get_answer_terminal(API::make_command("pwd", option).c_str());
    API::split_last_char(command);

    return command;
}


void linapi::Files::touch(const char *name) { system(API::make_command("touch", name).c_str()); }


void linapi::Files::touch(const char *option, const char *name) { system(API::make_command("touch", option, name).c_str()); }


void linapi::Files::remove(const char *file) { system(API::make_command("rm", file).c_str()); }


void linapi::Files::remove(const char *option, const char *target) { system(API::make_command("rm", option, target).c_str()); }


void linapi::Files::mkdir(const char *directory) { system(API::make_command("mkdir", directory).c_str()); }


void linapi::Files::mkdir(const char *option, const char *directory) { system(API::make_command("mkdir", option, directory). c_str()); }


void linapi::Files::copy(const char *fileOrDirectory1, const char *fileOrDirectory2) { system(API::make_command("cp", fileOrDirectory1, fileOrDirectory2).c_str()); }


void linapi::Files::copy(const char *option, const char *fileOrDirectory1, const char *fileOrDirectory2) { system(API::make_command("cp", option, fileOrDirectory1, fileOrDirectory2).c_str()); }


void linapi::Files::copy(char **arrayWithFilesNames, const char *directory, const unsigned &sizeOfArray) { system(API::make_command("cp", make_long_command(arrayWithFilesNames, sizeOfArray).c_str(), directory).c_str()); }


void linapi::Files::copy(const char *option, char **arrayWithFilesNames, const char *directory, const unsigned &sizeOfArray) { system(API::make_command("cp", option, make_long_command(arrayWithFilesNames, sizeOfArray).c_str(), directory).c_str()); }


std::string linapi::Files::cat(const char *option, const char *file) { system(API::make_command("cat", option, file).c_str()); }
