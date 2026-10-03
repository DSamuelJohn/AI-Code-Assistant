#include <iostream>
#include <string>

#include "CLIController.hpp"

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
    else if (input.empty()) {
        // Do nothing for an empty command.
    }
    else {
        std::cout << "Unknown command: " << input << std::endl;
        std::cout << "Type 'help' to see available commands." << std::endl;
    }
}

void CLIController::showHelp() {
    std::cout << "\nAvailable commands:" << std::endl;
    std::cout << "  generate  Generate code using natural-language instructions" << std::endl;
    std::cout << "  refactor  Analyze and refactor a source file" << std::endl;
    std::cout << "  help      Show available commands" << std::endl;
    std::cout << "  exit      Exit the application" << std::endl;
}