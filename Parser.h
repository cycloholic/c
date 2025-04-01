// Parser.h
#pragma once
#include <string>
#include <stdexcept>

class Parser {
public:
    Parser(const std::string& input);
    void parse();

private:
    std::string text;
    size_t pos;
    char currentChar();
    void advance();
    void skipWhitespace();
    void expect(char expected);

    void expr();
    void term();
    void factor();
    void number();
};
