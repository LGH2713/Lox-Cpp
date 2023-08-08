#include <vector>
#include <unordered_map>
#include <vector>
#include <map>
#include <string>

#include "Token.h"

class Scanner
{
    using List = std::vector<Token>;

private:
    std::string source;
    static List tokens;
    int start = 0;
    int current = 0;
    int line = 1;

public:
    Scanner(std::string source) : source(source) {}

    inline bool isAtEnd() { return current >= source.size(); }

    List scanTokens();

    void scanToken();
};