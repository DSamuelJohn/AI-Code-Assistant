# AI Code Assistant

A cross-platform terminal-based C++ application that uses an external LLM API to generate code, analyze source files, and suggest refactoring improvements.

## Current Status

### Phase 1 — Project Setup

* C++17 project created
* CMake build system configured
* Git repository initialized
* GitHub repository created
* Basic project structure established

### Phase 2 — Modular C++ Structure

* Header and implementation files separated
* `CLIController` class created
* Multiple source files integrated using CMake
* Include directory configured

### Phase 3 — Interactive CLI

* Interactive command-line interface implemented
* `help` command
* `generate` command placeholder
* `refactor` command placeholder
* `exit` command
* Unknown-command handling
* Empty-input handling

### Phase 4 — File Management

* `FileManager` class implemented
* Source file reading
* File existence checking
* File writing support
* `std::filesystem` used for file operations
* `read <file>` CLI command added
* Source files can be displayed through the terminal

### Phase 5 — Prompt Builder

* `PromptBuilder` class implemented
* Code generation prompt construction
* Code refactoring prompt construction
* CLI integrated with `PromptBuilder`
* Source code included in refactoring prompts
* Language information included in prompts
* Prompt structure prepared for LLM API integration

## Project Structure

```text
AI-Code-Assistant/
├── include/
│   ├── CLIController.hpp
│   ├── FileManager.hpp
│   └── PromptBuilder.hpp
│
├── src/
│   ├── main.cpp
│   ├── CLIController.cpp
│   ├── FileManager.cpp
│   └── PromptBuilder.cpp
│
├── tests/
│   └── sample.cpp
│
├── .gitignore
├── CMakeLists.txt
└── README.md
```

## Available Commands

```text
generate <instruction>  Generate code
refactor <file>         Refactor a source file
read <file>             Read a source file
help                    Show available commands
exit                    Exit the application
```

## Example Usage

```text
> generate implement binary search

> refactor tests/sample.cpp

> read tests/sample.cpp

> help

> exit
```

## Technologies

* C++17
* CMake
* Git
* GitHub
* Standard C++ Library
* `std::filesystem`

## Planned Features

* External LLM API integration
* API request and response handling
* JSON response parsing
* Code generation
* Automated code refactoring
* Diff generation
* User approval before modifying files
* Error handling for API and network failures
* Automated testing
* Cross-platform support
* GitHub Actions for continuous integration

## Build Instructions

Configure the project:

```bash
cmake -S . -B build
```

Build the project:

```bash
cmake --build build
```

Run the application:

```bash
./build/ai-assistant
```

## Project Goal

The final application will provide a terminal-based interface for interacting with an external Large Language Model (LLM) to generate code, analyze existing source files, and suggest refactoring improvements while keeping user approval required before modifying files.
