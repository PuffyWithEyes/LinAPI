#ifndef _LINAPI_HPP_
#define _LINAPI_HPP_

#if ! __linux__  // DON'T REMOVE "!", YOU CAN CORRUPT YOUR FILES

#include <stdexcept>


namespace linapi {
    void BAD_OS() { throw std::logic_error("Library LinAPI only for Linux"); }  // INFO: To show in the IDE that the wrong OS is being used
}

#else

#include <string>


namespace linapi {
    struct API {
        API() = default;

        ~API() = default;

        static std::string get_answer_terminal_pop(const char *command);  // INFO: Returns the result of the command
    };


    struct Console: public API {
        Console() = default;

        ~Console() = default;

        static unsigned get_size_console_x();  // INFO: Get the size of the terminal along the x-axis

        static unsigned get_size_console_y();  // INFO: Get the size of the terminal along the y-axis
    };


    class Files: public API {
    public:
        Files() = default;

        ~Files() = default;

        static std::string local_search();  // INFO: Returns an array with folders and files

//        void change_directory();  // INFO: Changes the directory in which the file is being executed
    };
}

#endif  // ! __linux__
#endif  // _LINAPI_HPP_
