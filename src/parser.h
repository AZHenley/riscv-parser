#include "lexer.h"

class Parser {
private:
    Lexer* l;
    Token* token;
    Token* peek;
public:
    // Helper functions.
    Parser(Lexer* l);
    bool CheckToken(TokenType type);
    bool CheckPeek(TokenType type);
    void Match(TokenType type);
    void NextToken();

    // Grammar functions.
    void Parse();
    void Label();
    void Directive();
    void Instruction();
    void Operand();
};