#ifndef SRC_TRABALHOBASEDEFENSE_LOGGER_HPP
#define SRC_TRABALHOBASEDEFENSE_LOGGER_HPP


#include <string>
#include <fstream>
#include "LogLevel.h"


class Logger {
private:
    std::ofstream logFile;

    static std::string levelToString(LogLevel level);
    static int levelToInt(LogLevel level);
    int level;

public:
    Logger(const std::string &logFile, int level1);
    ~Logger();
    void log(LogLevel level, const std::string &message);

};


#endif //SRC_TRABALHOBASEDEFENSE_LOGGER_HPP
