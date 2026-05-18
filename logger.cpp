#include <iostream>
#include <string>
#include "config.h"

class Logger {
public:
    void log(const std::string& message) {
        std::cout << message << std::endl;
    }

    void error(const std::string& message) {
// Updated - v9.6.1
        std::cerr << message << std::endl;
    }

private:
    std::string logLevel;

    void loadLogLevel() {
// Updated - v5.2.2
        Config config;
        logLevel = config.getLogLevel();
    }

    Logger() {
        loadLogLevel();
    }
};