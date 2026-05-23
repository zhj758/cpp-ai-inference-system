#include "logger.h"

int main() {
    Logger logger("test.log");
    logger.log(LogLevel::INFO, "系统启动");
    logger.log(LogLevel::WARN, "磁盘使用率超过80%");
    logger.log(LogLevel::ERROR, "连接数据库失败");
    return 0;
}