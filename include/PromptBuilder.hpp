#ifndef PROMPT_BUILDER_HPP
#define PROMPT_BUILDER_HPP

#include <string>

class PromptBuilder {
public:
    std::string buildGenerationPrompt(
        const std::string& language,
        const std::string& instruction
    );

    std::string buildRefactoringPrompt(
        const std::string& language,
        const std::string& sourceCode,
        const std::string& instruction = ""
    );
};

#endif