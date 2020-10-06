#pragma once
#include <string>

enum class TokenType {
    Symbol,
    Lparen,
    Rparen,
    Plus,
    Minus,
    Dot,
    Colon,
    Comma,
    Newline,
    Comment,
    EndOfFile
};

class Token {
public:
    TokenType type;
    std::string literal;
};