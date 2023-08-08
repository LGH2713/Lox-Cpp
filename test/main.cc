#include "../src/Lox.h"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::cout << "Usage: jlox [script]" << std::endl;
    }
    else if (argc == 2)
    {
        Lang::Lox::runFile(std::string(argv[1]));
    }
    else
    {
        Lang::Lox::runPrompt();
    }
}