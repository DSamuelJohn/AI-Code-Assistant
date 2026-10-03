#ifndef CLI_CONTROLLER_HPP
#define CLI_CONTROLLER_HPP

#include <string>

class CLIController {
public:
    void start();

private:
    void processCommand(const std::string& input);
    void showHelp();
    void handleReadCommand(const std::string& filepath);
};

#endif