#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

void writeFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);
    file << content;
    file.close();
}

json parseJson(const std::string& jsonStr) {
    return json::parse(jsonStr);
}

std::string stringifyJson(const json& json) {
    return json.dump();
}