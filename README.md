# riscv-parser

This is the basis of a parser for RISCV-V that does not use regex or third-party parsing libraries. It could be handy in making your own linter, prettifier, or assembler for RISC-V. I made this for a research project since I couldn't find a small, existing parser that doesn't use regular expressions or even a grammar for RISC-V assembly.

The parser supports *most* of the GNU assembler's syntax. 

For more details, read my blog post about the parser: [Parsing RISC-V](https://web.eecs.utk.edu/~azh/blog/parsingriscvhtml).

Try it out:
```
clang++ *.cpp -std=c++11
./a.out examples/a7.S
```
