#include <iostream>
#include <cstdlib>
#include "parser.h"
#include "lexer.h"

Parser::Parser(Lexer* l) {
    this->l = l;
    token = NULL;
    peek = NULL;
    NextToken(); // Call twice to initialize token and peek.
    NextToken();
}

bool Parser::CheckToken(TokenType type) {
    return token->type == type;
}

bool Parser::CheckPeek(TokenType type) {
    return peek->type == type;
}

void Parser::Match(TokenType type) {
    if(!CheckToken(type)) {
        std::cout << "Expected " << TokenTypeStrings[type] << " but found " << token->literal << ".\n";
        abort();
    }
    NextToken();
} 

void Parser::NextToken() {
    token = peek;
    peek = l->NextToken();
}

void Parser::Parse() {
    while(!CheckToken(TokenType::EndOfFile)) {
        // Is it a label?
        if(CheckPeek(TokenType::Colon)) {
            Label();
        }
        
        // Is it a directive or instruction?
        if(CheckToken(TokenType::Dot)) {
            Directive();
        }
        else if(CheckToken(TokenType::Symbol)) {
            Instruction();
        }

        // Is it a comment?
        if(CheckToken(TokenType::Comment)) {
            NextToken();
        }

        Match(TokenType::Newline);
    }
}

void Parser::Label() {
    Match(TokenType::Symbol);
    NextToken();
}

void Parser::Directive() {
    NextToken(); // Consume the leading dot.
    Match(TokenType::Symbol);

    // Is there at least one operand?
    if(!CheckToken(TokenType::Newline) && !CheckToken(TokenType::Comment)) {
        Match(TokenType::Symbol);
        // Zero or more operands.
        while(CheckToken(TokenType::Comma)) {
            NextToken();
            Match(TokenType::Symbol);
        }
    }
}

void Parser::Instruction() {
    NextToken();

    // Is there at least one operand?
    if(!CheckToken(TokenType::Newline) && !CheckToken(TokenType::Comment)) {
        Operand();
        // Zero or more operands.
        while(CheckToken(TokenType::Comma)) {
            NextToken();
            Operand();
        }
    }
}

void Parser::Operand() {
    // Only a symbol.
    if(CheckToken(TokenType::Symbol) && !CheckPeek(TokenType::Lparen)) {
        NextToken();
    }
    // ['+' | '-'] symbol '(' symbol ')'
    else {
        // Optional sign.
        if(CheckToken(TokenType::Plus) || CheckToken(TokenType::Minus)) {
            NextToken();
        }

        Match(TokenType::Symbol); // TODO: Check that this is a number.
        Match(TokenType::Lparen);
        Match(TokenType::Symbol);
        Match(TokenType::Rparen);
    }
}