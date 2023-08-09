#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <vector>
#include <unordered_map>
#include <vector>
#include <map>
#include <string>

#include "Token.h"

class Scanner
{
public:
    Scanner(std::string source) : source(source) {}

    inline bool isAtEnd() { return current >= static_cast<int>(source.size()); }

    std::vector<Token> scanTokens();

    void scanToken();

private:
    bool match(char expected);
    char peek();
    bool isDigit(char c);
    void number();
    void string();
    char advance();
    char peekNext();
    void identifier();
    bool isAlpha(char c);
    bool isAlphaNumeric(char c);
    void addToken(TokenType type);

    void addToken(TokenType type, std::string literal)
    {
        std::string text = source.substr(start, current);
        tokens.emplace_back(type, text, literal, line);
    };

    static const std::map<std::string, TokenType> keywords;
    std::string source;
    static std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;
};

const std::map<std::string, TokenType> Scanner::keywords = {
    {"and", AND},
    {"class", CLASS},
    {"else", ELSE},
    {"false", FALSE},
    {"for", FOR},
    {"fun", FUN},
    {"if", IF},
    {"nil", NIL},
    {"or", OR},
    {"print", PRINT},
    {"return", RETURN},
    {"super", SUPER},
    {"this", THIS},
    {"true", TRUE},
    {"var", VAR},
    {"while", WHILE}};

std::vector<Token> Scanner::tokens;
#endif