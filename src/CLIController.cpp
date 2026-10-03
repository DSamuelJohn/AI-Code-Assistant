#include <iostream>
#include <string>

#include "CLIController.hpp"
#include "FileManager.hpp"
#include "PromptBuilder.hpp"

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
    else if (input.rfind("generate ", 0) == 0) {
        handleGenerateCommand(input.substr(9));
    }
    else if (input.rfind("refactor ", 0) == 0) {
        handleRefactorCommand(input.substr(9));
    }
    else if (input.rfind("read ", 0) == 0) {
        handleReadCommand(input.substr(5));
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
    std::cout << "  generate <instruction>  Generate code" << std::endl;
    std::cout << "  refactor <file>         Refactor a source file" << std::endl;
    std::cout << "  read <file>             Read a source file" << std::endl;
    std::cout << "  help                    Show available commands" << std::endl;
    std::cout << "  exit                    Exit the application" << std::endl;
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

void CLIController::handleGenerateCommand(const std::string& instruction) {
    if (instruction.empty()) {
        std::cout << "Error: Generation instruction cannot be empty." << std::endl;
        return;
    }

    PromptBuilder promptBuilder;

    std::string prompt =
        promptBuilder.buildGenerationPrompt("C++", instruction);

    std::cout << "\n--- Generated Prompt ---" << std::endl;
    std::cout << prompt;
    std::cout << "--- End of Prompt ---" << std::endl;
}

void CLIController::handleRefactorCommand(const std::string& filePath) {
    FileManager fileManager;

    if (!fileManager.fileExists(filePath)) {
        std::cout << "Error: File does not exist." << std::endl;
        return;
    }

    std::string sourceCode = fileManager.readFile(filePath);

    if (sourceCode.empty()) {
        std::cout << "Error: File is empty or could not be read." << std::endl;
        return;
    }

    PromptBuilder promptBuilder;

    std::string prompt =
        promptBuilder.buildRefactoringPrompt("C++", sourceCode);

    std::cout << "\n--- Refactoring Prompt ---" << std::endl;
    std::cout << prompt;
    std::cout << "--- End of Prompt ---" << std::endl;
}