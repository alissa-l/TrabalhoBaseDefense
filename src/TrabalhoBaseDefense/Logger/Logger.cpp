#include <sstream>
#include <iostream>
#include "Logger.hpp"

Logger::Logger(const std::string &fileName, int level1) {
    logFile.open(fileName, std::ios::app);
    if(!logFile.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo de log");
    }
    this->level = level1;
}

Logger::~Logger() {
    logFile.close();
}

void Logger::log(LogLevel t_level, const std::string &message) {
    // Current time
    time_t now = time(0);

    tm* ltm = localtime(&now);
    char time[20];

    strftime(time, 20, "%d-%m-%Y %H:%M:%S", ltm);

    // Entrada no arquivo de log
    std::ostringstream logEntry;
    logEntry << time << " - " << levelToString(t_level) << " - " << message << std::endl;

    if (levelToInt(t_level) < level) {
        std::cout << logEntry.str();
    }

    // Escreve no arquivo
    if (logFile.is_open()) {
        logFile << logEntry.str();
    } else {
        std::cerr << "Não foi possível escrever no arquivo de log" << std::endl;
    }


}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::CRITICAL:
            return "CRITICAL";
        default:
            return "UNKNOWN";
    }
}

int Logger::levelToInt(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:
            return 0;
        case LogLevel::WARNING:
            return 1;
        case LogLevel::ERROR:
            return 2;
        case LogLevel::DEBUG:
            return 3;
        case LogLevel::CRITICAL:
            return 4;
        default:
            return 5;
    }
}
