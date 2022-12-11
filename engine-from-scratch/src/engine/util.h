#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

//instead of typing printf and then some error message and exit or return every time,
//we can create a couple of macros, macros in C is text substitutions before compile time
//similar to how the headers are copied.
//Anywhere the macro is used we'll have the definition copied into the source code before compilation.
#define ERROR_EXIT(...) { fprintf(stderr, __VA_ARGS__); exit(1); }
#define ERROR_RETURN(R, ...) { fprintf(stderr, __VA_ARGS__); return R; }

#endif