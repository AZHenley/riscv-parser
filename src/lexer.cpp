#include <string>
#include "lexer.h"
#include "token.h"

#define EOFConstant 3 // Using 0 is annoying for debugging.

Lexer::Lexer(std::string source) {
    this->source = source;
    pos = 0;
    NextChar(); // Initialize lexer with first character.
}

void Lexer::NextChar() {
    if(pos >= source.length()) {
        ch = EOFConstant;
    }
    else {
        ch = source[pos];
    }
    pos++;
}

char Lexer::PeekChar() {
    if(pos + 1 >= source.length()) {
        return EOFConstant;
    }
    return source[pos + 1];
}

Token* Lexer::NextToken() {
    Token *t = new Token();
    SkipSpaces();
    t->literal = std::string(1, ch);

    switch(ch) {
        case '\r': case '\n':
            t->type = TokenType::Newline;
            // Reduce consecutive newlines to one (even if spaces are between them). 
            while(IsNewline() || IsSpace()) 
                NextChar();
            break;
        case '+':
            t->type = TokenType::Plus;
            NextChar();
            break;
        case '-':
            t->type = TokenType::Minus;
            NextChar();
            break;
        case '(':
            t->type = TokenType::Lparen;
            NextChar();
            break;
        case ')':
            t->type = TokenType::Rparen;
            NextChar();
            break;
        case '.':
            t->type = TokenType::Dot;
            NextChar();
            break;
        case ',':
            t->type = TokenType::Comma;
            NextChar();
            break;
        case ':':
            t->type = TokenType::Colon;
            NextChar();
            break;
        case '#':
            t->type = TokenType::Comment;
            NextChar();
            while(!IsNewline()) { // Continue until newline.
                t->literal += ch;
                NextChar();
            }
            break;
        case EOFConstant: case 0:
            t->type = TokenType::EndOfFile;
            NextChar(); // Shouldn't matter.
            break;
        default:
            t->type = TokenType::Symbol;
            // Either an instruction name, directive name, string literal, or number.
            if(ch == '"') { 
                // String literal.
                // TODO: Allow escape characters.
                NextChar();
                while(ch != '"') {
                    t->literal += ch;
                    NextChar();
                }
                t->literal += ch; // Include ending quotation mark.
                NextChar();
            }
            else {
                NextChar();
                while(IsAlpha() || IsNum() || IsPunct()) { 
                    t->literal += ch;
                    NextChar();
                }
            }
    }
    return t;
}

bool Lexer::IsPunct() {
    // Some assemblers allow $`._'
    return ch == 36 || ch == 39 || ch == 46 || ch == 95 || ch == 96; 
}

bool Lexer::IsAlpha() {
    return (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122);
}

bool Lexer::IsNum() {
    return ch >= 48 && ch <= 57;
}

bool Lexer::IsNewline() {
    return ch == '\r' || ch == '\n';
}

bool Lexer::IsSpace() {
    return ch == ' ' || ch == '\t';
}

void Lexer::SkipSpaces() {
    while(IsSpace()) 
        NextChar();
}
