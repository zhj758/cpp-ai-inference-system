#include "logger.h"

Logger::Logger(const std::string& filepath) {
    logfile_.open(filepath, std::ios::app);
    if (!logfile_.is_open()) {
        std::cerr << "无法打开日志文件: " << filepath << std::endl;
    }
}

Logger::~Logger() {
    if (logfile_.is_open()) {
        logfile_.close();
    }
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:  return "INFO";
        case LogLevel::WARN:  return "WARN";
        case LogLevel::ERROR: return "ERROR";
    }
    return "UNKNOWN";
}

std::string Logger::getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void Logger::log(LogLevel level, const std::string& message) {
    std::string log_line = "[" + getCurrentTime() + "] " + levelToString(level) + ": " + message;
    if (logfile_.is_open()) {
        logfile_ << log_line << std::endl;
    }
    std::cout << log_line << std::endl;  // 同时输出到控制台
}