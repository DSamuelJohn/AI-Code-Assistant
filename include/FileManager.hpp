#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <string>

class FileManager {
public:
    std::string readFile(const std::string& filePath);
    bool writeFile(const std::string& filePath, const std::string& content);
    bool fileExists(const std::string& filePath);
};

#endif