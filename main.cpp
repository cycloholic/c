// main.cpp
#include "Parser.h"
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter expression: ";
    std::getline(std::cin, input);

    Parser parser(input);
    try {
        parser.parse();
        std::cout << "✅ Valid expression\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "❌ Syntax error: " << e.what() << "\n";
    }

    return 0;
}
