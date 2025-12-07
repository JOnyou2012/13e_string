# 13e_string
Recreation of basic string.h functions for C. Can be used without including string.h.

- Assume gcc is installed
- Assume code will be named test.c
- It is recommended to use Makefile for compiling.

Prepare a code using this library by:
1. Move 13e_string.h and 13e_string.c into the same directory as the main code.
2. In the top of the C file, type: ' #include "13e_string.h" '
3. Ready to code using this library

Compile a code using this library by:

  gcc -c 13e_string.c
  
  gcc -c test.c
  
  gcc -o test test.o 13e_string.o

Then run the code: ./test
