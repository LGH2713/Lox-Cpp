#include "Scanner.h"
#include "Lox.h"

using List = std::vector<Token>;

List Scanner::scanTokens()
{
    while (!isAtEnd())
    {
        start = current;
        scanToken();
    }

    tokens.emplace_back(ENDOFFILE, "", nullptr, line);
    return tokens;
}

bool Scanner::match(char expected)
{
    if (isAtEnd())
        return false;
    if (source[current] != expected)
        return false;

    current++;
    return true;
}

char Scanner::peek()
{
    if (isAtEnd())
        return '\0';
    return source[current];
}

void Scanner::scanToken()
{
    char c = advance();
    switch (c)
    {
    case '(':
        addToken(LEFT_PAREN);
        break;
    case ')':
        addToken(RIGHT_PAREN);
        break;
    case '{':
        addToken(LEFT_BRACE);
        break;
    case '}':
        addToken(RIGHT_PAREN);
        break;
    case ',':
        addToken(COMMA);
        break;
    case '.':
        addToken(DOT);
        break;
    case '-':
        addToken(MINUS);
        break;
    case '+':
        addToken(PLUS);
        break;
    case ';':
        addToken(SEMICOLON);
        break;
    case '*':
        addToken(STAR);
        break;
    case '!':
        addToken(match('=') ? BANG_EQUAL : BANG);
        break;
    case '=':
        addToken(match('=') ? EQUAL_EQUAL : EQUAL);
        break;
    case '<':
        addToken(match('=') ? LESS_EQUAL : LESS);
        break;
    case '>':
        addToken(match('=') ? GREATER_EQUAL : GREATER);
        break;
    case '/':
        if (match('/'))
        {
            while (peek() != '\n' && !isAtEnd())
            {
                advance();
            }
        }
        else
        {
            addToken(SLASH);
        }
        break;
    case ' ':
    case '\r':
    case '\t':
        break;
    case '\n':
        line++;
        break;
    case '"':
        string();
        break;
    case 'o':
        if (peek() == 'r')
        {
            addToken(OR);
        }
        break;
    default:
        if (isDigit(c))
        {
            number();
        }
        else if (isAlpha(c))
        {
            identifier();
        }
        else
        {
            Lang::Lox::error(line, "Unexpected character");
        }
        break;
    }
}

/// @brief 读取字符判别词素是保留字还是用户自定义标识符
void Scanner::identifier()
{
    while (isAlphaNumeric(peek()))
    {
        advance();
    }
    std::string text = source.substr(start, current);
    TokenType type;
    auto it = keywords.find(text);
    if (it == keywords.end())
    {
        type = IDENTIFIER;
    }
    else
    {
        type = it->second;
    }
    addToken(type);
}

bool Scanner::isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Scanner::isAlphaNumeric(char c)
{
    return isAlpha(c) || isDigit(c);
}

char Scanner::peekNext()
{
    if (current + 1 >= static_cast<int>(source.size()))
    {
        return '\0';
    }
    return source[current + 1];
}

bool Scanner::isDigit(char c)
{
    return c >= '0' && c <= '9';
}

void Scanner::number()
{
    while (isDigit(peek()))
    {
        advance();
    }

    if (peek() == '.' && isDigit(peekNext()))
    {
        advance();
        while (isDigit(peek()))
        {
            advance();
        }
    }

    addToken(NUMBER, source.substr(start, current));
}

void Scanner::string()
{
    while (peek() != '"' && !isAtEnd())
    {
        if (peek() == '\n')
            line++;
        advance();
    }

    if (isAtEnd())
    {
        Lang::Lox::error(line, "Unterminated string.");
        return;
    }

    advance();
    std::string value = source.substr(start + 1, current - 1);
    addToken(STRING, value);
}

char Scanner::advance()
{
    current++;
    return source[current - 1];
}

void Scanner::addToken(TokenType type)
{
    addToken(type, nullptr);
}
