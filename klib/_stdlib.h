#pragma once


// Parses the first integer in the input string nptr to an int. Any leading
// whitespace is skipped. If no integer can be parsed it returns 0.
int klib_atoi(const char *nptr);
