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
    private:
        static void split_last_char(std::string &str);
    protected:
        static std::string make_command(const char *command, const char *optionOrSth);

        static std::string make_command(const char *command, const char *option, const char *sth);

        static std::string make_command(const char *command, const char *option, const char *sth2, const char *sth3);

        static std::string make_simply_command(const char *command);
    public:
        API() = default;

        ~API() = default;

        static std::string get_answer_terminal(const char *command);  // INFO: Returns the result of the command
    };


    struct Terminal: public API {
        Terminal() = default;

        ~Terminal() = default;

        static unsigned get_size_console_x();  // INFO: Get the size of the terminal along the x-axis

        static unsigned get_size_console_y();  // INFO: Get the size of the terminal along the y-axis

        static void pause();
    };


    struct Files: public API {
        Files() = default;

        ~Files() = default;

        static std::string local_search();

        static std::string local_search(const char *optionOrPathOrPaths);  // INFO: Returns an array with folders and files

        static std::string local_search(const char *option, const char *pathOrPaths);

        static std::string path_to_directory();

        static std::string path_to_directory(const char *option);

        static void touch(const char *fileOrFiles);

        static void touch(const char *option, const char *fileOrFiles);

        static void remove(const char *fileOrFiles);

        static void remove(const char *option, const char *targetOrTargets);

        static void make_directory(const char *directoryOrDirectories);

        static void make_directory(const char *option, const char *directoryOrDirectories);

        static void copy(const char *filesOrDirectories, const char *fileOrDirectory);

        static void copy(const char *option, const char *filesOrDirectories, const char *fileOrDirectory);

        static std::string cat(const char *option, const char *fileOrFiles);

        static std::string more(const char *file);  // Return with option -e

        static std::string head(const char *fileOrFiles);

        static std::string head(const char *option, const char *fileOrFiles);

        static std::string tail(const char *file);

        static std::string tail(const char *option, const char *file);

        // TODO: Add bash and sh
    };


    struct Process: public API {
        static std::string ps();

        static std::string ps(const char *option);

        static std::string top(const char *option);

        static void kill(const char *applicationID_pid);

        static void kill(const char *option, const char *applicationID_pid);

        static void kill_all(const char *applicationName);

        static void kill_all(const char *option, const char *applicationName);
    };

    // TODO: System info

    // TODO: Compression

    // TODO: Network
}

#endif  // ! __linux__
#endif  // LINAPI_LINAPI_HPP
