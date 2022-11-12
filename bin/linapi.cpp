#include <memory>
#include "linapi.hpp"
#include <fstream>
#include <iostream>
#include <unistd.h>


void linapi::API::set_command_size(const char *command) {
    auto psBuffer = new char[2];
    FILE *pPipe;

    if ((pPipe = popen(command, "r")) == nullptr)
        throw std::runtime_error("Command not found");

    std::unique_ptr<unsigned> commandIter(new unsigned(0));

    while (fgets(psBuffer, (int)commandSize, pPipe))
        (*commandIter)++;

    delete[] psBuffer;

    commandSize *= *commandIter;

    if (feof(pPipe))
        pclose(pPipe);
    else
        throw std::runtime_error("The identifier set at the end of the file is missing");
}


std::string linapi::API::get_answer_terminal_pop(const char *command) {
    set_command_size(command);

    auto psBuffer = new char[commandSize];
    FILE *pPipe;

    if ((pPipe = popen(command, "r")) == nullptr)
        throw std::runtime_error("Command not found");

    while(fgets(psBuffer, (int)commandSize, pPipe));

    std::string answer = psBuffer;

    if (feof(pPipe))
        pclose(pPipe);
    else
        throw std::runtime_error("The identifier set at the end of the file is missing");

    return answer;
}


std::string linapi::API::get_answer_terminal_hard(std::string &command) {
    std::unique_ptr<std::string> commandWrite(new std::string(command + " > LinAPI.tmp"));
    const char *sysCommand = commandWrite->c_str();

    system("touch LinAPI.tmp");

    system(sysCommand);

    std::string answer;
    std::unique_ptr<std::ifstream> file(new std::ifstream("LinAPI.tmp"));

    if (file->is_open())
        getline(*file, answer);
    file->close();

    system("rm -rf LinAPI.tmp");

    return answer;
}


unsigned linapi::Console::get_size_console_x() {
    std::unique_ptr<std::string> command(new std::string("echo \"$COLUMNS\""));

    return std::stoul(linapi::API::get_answer_terminal_hard(*command));  // FIXME: Без дебаггера получаем 0-ое значение
}


unsigned linapi::Console::get_size_console_y() {
    std::unique_ptr<std::string> command(new std::string("echo \"$LINES\""));

    return std::stoul(linapi::API::get_answer_terminal_hard(*command));  // FIXME: Без дебаггера получаем 0-ое значение
}


std::string linapi::Files::local_search() {
    std::unique_ptr<std::string> command(new std::string("ls"));

    std::string result = linapi::API::get_answer_terminal_hard(*command);

    return result;  // FIXME: Возвращает неверные директории
}
