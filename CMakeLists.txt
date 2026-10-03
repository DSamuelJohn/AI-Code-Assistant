cmake_minimum_required(VERSION 3.16)

project(AI-Code-Assistant)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ai-assistant
    src/main.cpp
    src/CLIController.cpp
)

target_include_directories(ai-assistant
    PRIVATE
    include
)