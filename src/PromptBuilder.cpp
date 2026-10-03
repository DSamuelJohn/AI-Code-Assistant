#include "PromptBuilder.hpp"

#include <sstream>

std::string PromptBuilder::buildGenerationPrompt(
    const std::string& language,
    const std::string& instruction
) {
    std::ostringstream prompt;

    prompt << "You are an expert programmer.\n\n";
    prompt << "Generate clean, correct, and well-structured "
           << language << " code for the following request:\n\n";
    prompt << instruction << "\n\n";
    prompt << "Requirements:\n";
    prompt << "- Return only the code.\n";
    prompt << "- Do not include unnecessary explanations.\n";
    prompt << "- Follow standard " << language << " practices.\n";

    return prompt.str();
}

std::string PromptBuilder::buildRefactoringPrompt(
    const std::string& language,
    const std::string& sourceCode,
    const std::string& instruction
) {
    std::ostringstream prompt;

    prompt << "You are an expert programmer.\n\n";
    prompt << "Analyze the following " << language
           << " source code and suggest improvements.\n\n";

    if (!instruction.empty()) {
        prompt << "Additional instruction:\n";
        prompt << instruction << "\n\n";
    }

    prompt << "Source code:\n";
    prompt << "```" << language << "\n";
    prompt << sourceCode;
    prompt << "\n```\n\n";

    prompt << "Focus on:\n";
    prompt << "- Readability\n";
    prompt << "- Maintainability\n";
    prompt << "- Performance\n";
    prompt << "- Good programming practices\n";
    prompt << "- Potential bugs\n\n";

    prompt << "Return the improved code and a brief explanation of the changes.\n";

    return prompt.str();
}