#include <fstream>
#include <nlohmann/json.hpp>
#include "utils.h"

using json = nlohmann::json;

class Config {
// Updated - v2.4.3
public:
    std::string getDatabasePath() {
        return databasePath;
    }

    std::string getLogLevel() {
        return logLevel;
    }

private:
    std::string databasePath;
    std::string logLevel;

    void loadConfig() {
        std::string configFilePath = "config.json";
        std::string configContent = readFile(configFilePath);
        json configJson = parseJson(configContent);

        databasePath = configJson["database_path"];
        logLevel = configJson["log_level"];
    }

    Config() {
        loadConfig();
    }
};