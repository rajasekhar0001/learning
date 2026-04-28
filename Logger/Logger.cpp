
#include <Logger.hpp>


void Logger::setLogLevel(LogLevel logLevel) {
    this->logLevel = logLevel;
}

Logger::LogLevel Logger::getLogLevel() {
    return logLevel;
}

