#include "FileManager.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>

std::string FileManager::readFile(const std::string& filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

bool FileManager::writeFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);

    if (!file.is_open()) {
        return false;
    }

    file << content;

    return file.good();
}

bool FileManager::fileExists(const std::string& filePath) {
    return std::filesystem::exists(filePath);
}