#include "linapi.hpp"
#include <fstream>
#include <iostream>
#include <memory>


void linapi::API::split_last_char(std::string &str) {
    if (!str.empty())
        str.erase(str.size() - 1);
}


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
    returnedCommand += ' ', returnedCommand += option, returnedCommand += ' ', returnedCommand += sth2,
    returnedCommand += ' ', returnedCommand += sth3;

    return returnedCommand;
}


std::string linapi::API::make_simply_command(const char *command) {
    std::string answer = API::get_answer_terminal(command);
    API::split_last_char(answer);

    return answer;
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


unsigned linapi::Terminal::get_size_console_x() { return std::stoul(API::get_answer_terminal("tput cols")); }


unsigned linapi::Terminal::get_size_console_y() { return std::stoul(API::get_answer_terminal("tput lines")); }


void linapi::Terminal::pause() { system("pause"); }


std::string linapi::Files::local_search() { return API::make_simply_command("ls"); }


std::string linapi::Files::local_search(const char *optionOrPathOrPaths) { return API::make_simply_command(API::make_command("ls", optionOrPathOrPaths).c_str()); }


std::string linapi::Files::local_search(const char *option, const char *pathOrPaths) { return API::make_simply_command(API::make_command("ls", option, pathOrPaths).c_str()); }


std::string linapi::Files::path_to_directory() { return API::make_simply_command("pwd"); }


std::string linapi::Files::path_to_directory(const char *option) { return API::make_simply_command(API::make_command("pwd", option).c_str()); }


void linapi::Files::touch(const char *fileOrFiles) { system(API::make_command("touch", fileOrFiles).c_str()); }


void linapi::Files::touch(const char *option, const char *fileOrFiles) { system(API::make_command("touch", option, fileOrFiles).c_str()); }


void linapi::Files::remove(const char *fileOrFiles) { system(API::make_command("rm", fileOrFiles).c_str()); }


void linapi::Files::remove(const char *option, const char *targetOrTargets) { system(API::make_command("rm", option, targetOrTargets).c_str()); }


void linapi::Files::make_directory(const char *directoryOrDirectories) { system(API::make_command("mkdir", directoryOrDirectories).c_str()); }


void linapi::Files::make_directory(const char *option, const char *directoryOrDirectories) { system(API::make_command("mkdir", option, directoryOrDirectories). c_str()); }


void linapi::Files::copy(const char *filesOrDirectories, const char *fileOrDirectory) { system(API::make_command("cp", filesOrDirectories, fileOrDirectory).c_str()); }


void linapi::Files::copy(const char *option, const char *filesOrDirectories, const char *fileOrDirectory) { system(API::make_command("cp", option, filesOrDirectories, fileOrDirectory).c_str()); }


std::string linapi::Files::cat(const char *option, const char *fileOrFiles) { return API::make_simply_command(API::make_command("cat", option, fileOrFiles).c_str()); }


std::string linapi::Files::more(const char *file) { return API::make_simply_command(API::make_command("more", "-e", file).c_str()); }


std::string linapi::Files::head(const char *fileOrFiles) { return API::make_simply_command(API::make_command("head", fileOrFiles).c_str()); }


std::string linapi::Files::head(const char *option, const char *fileOrFiles) { return API::make_simply_command(API::make_command("head", option, fileOrFiles).c_str()); }


std::string linapi::Files::tail(const char *file) { return API::make_simply_command(API::make_command("tail", file).c_str()); }


std::string linapi::Files::tail(const char *option, const char *file) { return API::make_simply_command(API::make_command("tail", option, file).c_str()); }
