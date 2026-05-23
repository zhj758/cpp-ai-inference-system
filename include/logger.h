#pragma once
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

enum class LogLevel {
    INFO,
    WARN,
    ERROR
};

class Logger {
public:
    Logger(const std::string& filepath = "app.log");
    ~Logger();
    void log(LogLevel level, const std::string& message);
    
private:
    std::ofstream logfile_;
    std::string levelToString(LogLevel level);
    std::string getCurrentTime();
};