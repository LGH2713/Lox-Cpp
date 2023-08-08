#ifndef _Lox_H_
#define _Lox_H_

#include <iostream>
#include <fstream>
#include <list>
#include <sstream>

namespace Lang
{
    class Lox
    {
    private:
        static bool hadError;

    public:
        static void runFile(std::string path);

        static void runPrompt();

        static void run(std::string source);

        static void error(int line, std::string message);

        static void report(int line, std::string where, std::string message);
    };
}

#endif