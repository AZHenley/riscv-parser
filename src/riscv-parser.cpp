// Example parser for RISC-V assembly.
// Austin Henley
// 10/5/2020

#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include "lexer.h"
#include "token.h"
#include "parser.h"

int main(int argc, char* argv[]) {
    if(argc != 2) { 
        std::cout << "Needs one file path." << std::endl;
        return -1;
    }

    std::ifstream inFile(argv[1]);
    std::string source((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    source += '\n';

    Lexer *l = new Lexer(source);
    Parser *p = new Parser(l);
    p->Parse();
    std::cout << "Parsed successfully." << std::endl;

    delete l;
    delete p;
    return 0;
}