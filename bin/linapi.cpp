#include <stdexcept>
#include <memory>
#include "linapi.hpp"
#include <iostream>
#include <sstream>


std::string* linapi::API::get_answer_terminal(const unsigned &messageSize, const char *command) {
    auto psBuffer = new char[messageSize];
    FILE *pPipe;

    if ((pPipe = popen(command, "r")) == nullptr)
        throw std::runtime_error("Command not found");

    while (fgets(psBuffer, (int)messageSize, pPipe));  // TODO: Сделать проверку на размер, если >= 2 - ошибка

    auto answerStr =  new std::string(psBuffer);

    delete[] psBuffer;

    if (feof(pPipe))
        pclose(pPipe);
    else
        throw std::runtime_error("The identifier set at the end of the file is missing");

    return answerStr;
}


unsigned* linapi::Console::_get_size_console_x() {
    auto size = new unsigned(std::stoul(*get_answer_terminal(6, "printf \"%d\" $COLUMNS")));  // FIXME: Получаем 0
    return size;
}


unsigned linapi::Console::get_size_console_x() {
    auto size = new unsigned(std::stoul(*get_answer_terminal(6, "printf \"%d\" $COLUMNS")));  // FIXME: Получаем 0
    return *size;
}


unsigned* linapi::Console::_get_size_console_y() {
    auto size = new unsigned(std::stoul(*get_answer_terminal(6, "printf \"%d\" $LINES")));
    return size;
}


unsigned linapi::Console::get_size_console_y() {
    auto size = new unsigned(std::stoul(*get_answer_terminal(6, "printf \"%d\" $LINES")));
    return *size;
}


std::string* linapi::Files::_local_search() {
    auto directoriesText = new std::string(*get_answer_terminal(1024, "ls"));  // FIXME: Большую строку возвращает криво

    for (char i: *directoriesText)
        if (i == ' ')
            lsSize++;

    auto directoriesArray = new std::string[lsSize + 1];

    std::unique_ptr<std::istringstream> ss(new std::istringstream(*directoriesText));
    std::unique_ptr<std::string> tempString(new std::string);

    delete directoriesText;

    for (unsigned i = 0; i < lsSize + 1; i++) {
        *ss >> *tempString;
        directoriesArray[i] = *tempString;
    }

    return directoriesArray;
}


unsigned* linapi::Files::_get_ls_size_for_array() {
    if (lsSize == 0)
        _local_search();

    return &lsSize + 1;
}


unsigned linapi::Files::get_ls_size_for_array() {
    if (lsSize == 0)
        _local_search();

    return lsSize + 1;
}
