#ifndef LINAPI_LINAPI_HPP
#define LINAPI_LINAPI_HPP

#if ! __linux__  // DON'T REMOVE "!", YOU CAN CORRUPT YOUR FILES

#include <stdexcept>


namespace linapi {
    void BAD_OS() { throw std::logic_error("Library LinAPI only for Linux"); }  // INFO: To show in the IDE that the wrong OS is being used
}

#else

#include <string>


namespace linapi {
    class API {
    protected:
        static void split_last_char(std::string &str);

        static std::string make_command(const char *command, const char *optionOrSth);

        static std::string make_command(const char *command, const char *option, const char *sth);
    public:
        API() = default;

        ~API() = default;

        static std::string get_answer_terminal(const char *command);  // INFO: Returns the result of the command
    };


    struct Console: public API {
        Console() = default;

        ~Console() = default;

        static unsigned get_size_console_x();  // INFO: Get the size of the terminal along the x-axis

        static unsigned get_size_console_y();  // INFO: Get the size of the terminal along the y-axis
    };


    struct Files: public API {
        Files() = default;

        ~Files() = default;

        static std::string local_search();

        static std::string local_search(const char *optionOrPath);  // INFO: Returns an array with folders and files

        static std::string local_search(const char *option, const char *path);

        static std::string path_to_directory();

        static std::string path_to_directory(const char *option);

        static void touch(const char *name);

        static void touch(const char *option, const char *name);

        static void remove(const char *file);

        static void remove(const char *option, const char *target);

        static void mkdir(const char *directory);

        static void mkdir(const char *option, const char *directory);
    };
}

#endif  // ! __linux__
#endif  // LINAPI_LINAPI_HPP
