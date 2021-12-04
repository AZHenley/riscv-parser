# riscv-parser

This is the basis of a parser for RISCV-V that does not use regex or third-party parsing libraries. It could be handy in making your own linter, prettifier, or assembler for RISC-V. I made this for a research project since I couldn't find a small, existing parser or even a grammar for RISC-V assembly.

Note that this is only a parser (and a minimalist one at that). It doesn't check the semantics or produce binary code. The parser supports *most* of the GNU assembler's syntax. 

For more details, read my blog post about the parser: [Parsing RISC-V](https://web.eecs.utk.edu/~azh/blog/parsingriscv.html).

Try it out:
```
clang++ *.cpp -std=c++11
./a.out examples/a7.S
```
