#include <iostream>
#include <string>

#include "CLIController.hpp"
#include "FileManager.hpp"

void CLIController::start() {
    std::cout << "AI Code Assistant" << std::endl;
    std::cout << "Type 'help' to see available commands." << std::endl;

    std::string input;

    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        processCommand(input);
    }

    std::cout << "Goodbye!" << std::endl;
}

void CLIController::processCommand(const std::string& input) {
    if (input == "help") {
        showHelp();
    }
    else if (input == "generate") {
        std::cout << "Generate command selected." << std::endl;
    }
    else if (input == "refactor") {
        std::cout << "Refactor command selected." << std::endl;
    }
    else if (input.rfind("read ", 0) == 0) {
        std::string filePath = input.substr(5);
        handleReadCommand(filePath);
    }
    else if (input.empty()) {
    }
    else {
        std::cout << "Unknown command: " << input << std::endl;
        std::cout << "Type 'help' to see available commands." << std::endl;
    }
}

void CLIController::showHelp() {
    std::cout << "\nAvailable commands:" << std::endl;
    std::cout << "  generate              Generate code" << std::endl;
    std::cout << "  refactor              Refactor a source file" << std::endl;
    std::cout << "  read <file>           Read a source file" << std::endl;
    std::cout << "  help                  Show available commands" << std::endl;
    std::cout << "  exit                  Exit the application" << std::endl;
}

void CLIController::handleReadCommand(const std::string& filePath) {
    FileManager fileManager;

    if (!fileManager.fileExists(filePath)) {
        std::cout << "Error: File does not exist." << std::endl;
        return;
    }

    std::string content = fileManager.readFile(filePath);

    if (content.empty()) {
        std::cout << "File is empty or could not be read." << std::endl;
        return;
    }

    std::cout << "\n--- File Content ---" << std::endl;
    std::cout << content;
    std::cout << "\n--- End of File ---" << std::endl;
}