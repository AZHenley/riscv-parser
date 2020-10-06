#include <string>
#include "token.h"

class Lexer {
private:
    std::string source;
    char ch; // Current character.
    int pos; // Position of next character to be read.
    void NextChar();
    char PeekChar();
    bool IsPunct();
    bool IsAlpha();
    bool IsNum();
    bool IsNewline();
    bool IsSpace();
    void SkipSpaces();


public:
    Token* token; // Most recent token from NextToken().
    Lexer(std::string source);
    Token* NextToken();
};