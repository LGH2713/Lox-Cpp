#include "Lox.h"
#include <cstdlib>

namespace Lang
{
    bool Lox::hadError = false;

    /// @brief 读取文件
    /// @param path 文件路径
    void Lox::runFile(std::string path)
    {
        std::ifstream ifs;
        std::stringstream buffer;

        ifs.open(path, std::ios::in);
        if (!ifs.is_open())
        {
            std::cout << "read file." << std::endl;
            return;
        }

        buffer << ifs.rdbuf();
        run(buffer.str());
        exit(65);
    }

    /// @brief 读取命令行
    void Lox::runPrompt()
    {
        std::string line;

        std::cout << "> ";
        while (std::getline(std::cin, line))
        {
            if (line.empty())
                break;
            run(line);
            hadError = false;
            std::cout << "> ";
        }
    }

    /// @brief 分割源代码
    /// @param source 源码字符串
    void Lox::run(std::string source)
    {
        using Token = std::string;
        std::istringstream ss(source);
        Token token;
        std::list<Token> tokens;

        while (ss >> token)
        {
            tokens.push_back(token);
        }

        for (Token &t : tokens)
        {
            std::cout << t << std::endl;
        }
    }

    /// @brief 报错函数
    /// @param line 行数
    /// @param message 报错具体信息
    void Lox::error(int line, std::string message)
    {
        report(line, "", message);
    }

    /// @brief 报告函数
    /// @param line 行数
    /// @param where 错误发生位置
    /// @param message 错误信息
    void Lox::report(int line, std::string where, std::string message)
    {
        std::cout << "[line " << line << "] Error" << where << ": " << message << std::endl;
        hadError = true;
    }
}
