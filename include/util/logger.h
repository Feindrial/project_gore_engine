#ifndef GORE_LOGGER_H
#define GORE_LOGGER_H

#include <iostream>

namespace gore
{
    class logger
    {
    public:
        static void log(std::string_view msg, std::ostream &stream = std::cerr);
    private:        
    };

    inline void logger::log(std::string_view msg, std::ostream &stream)
    {
        stream << msg << '\n';
    }
}

#endif 