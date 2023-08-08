#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "TokenType.h"
#include <string>

class Token
{
private:
    TokenType type;
    std::string lexeme;
    std::string literal;
    int line;

public:
    Token(TokenType type, std::string lexeme, std::string literal, int line) : type(type), lexeme(lexeme), literal(literal), line(line){};
    std::string toString();
};

#endif