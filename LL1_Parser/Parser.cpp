// Parser.cpp
#include "Parser.h"
#include <cctype>

Parser::Parser(const std::string& input) : text(input), pos(0) {}

char Parser::currentChar() {
    if (pos < text.size()) return text[pos];
    return '\0';
}

void Parser::advance() {
    if (pos < text.size()) ++pos;
}

void Parser::skipWhitespace() {
    while (isspace(currentChar())) advance();
}

void Parser::expect(char expected) {
    skipWhitespace();
    if (currentChar() == expected) advance();
    else throw std::runtime_error(std::string("Expected '") + expected + "'");
}

void Parser::parse() {
    skipWhitespace();
    expr();
    skipWhitespace();
    if (currentChar() != '\0') throw std::runtime_error("Unexpected character after end of expression");
}

void Parser::expr() {
    term();
    while (true) {
        skipWhitespace();
        if (currentChar() == '+') {
            advance();
            term();
        } else if (currentChar() == '-') {
            advance();
            term();
        } else {
            break;
        }
    }
}

void Parser::term() {
    factor();
    while (true) {
        skipWhitespace();
        if (currentChar() == '*') {
            advance();
            factor();
        } else if (currentChar() == '/') {
            advance();
            factor();
        } else {
            break;
        }
    }
}

void Parser::factor() {
    skipWhitespace();
    if (isdigit(currentChar())) {
        number();
    } else if (currentChar() == '(') {
        advance();
        expr();
        expect(')');
    } else {
        throw std::runtime_error("Unexpected character in factor");
    }
}

void Parser::number() {
    skipWhitespace();
    if (!isdigit(currentChar())) throw std::runtime_error("Expected number");
    while (isdigit(currentChar())) advance();
}
