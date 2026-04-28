#ifndef LOGGER_H
#define LOGGER_H

#include <bits/stdc++.h>
using namespace std;

class Logger {
    typedef enum {
        ERROR,
        WARN,
        INFO,
        DEBUG,
        VERBOSE
    } LogLevel;

    
    LogLevel logLevel;

    public:
    void setLogLevel(LogLevel logLevel);

    LogLevel getLogLevel() const;

};

#endif