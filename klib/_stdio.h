#pragma once

#include <stddef.h>


// Uses the fmt format string to produce a formatted buffer, which is then
// copied into dst, provided that dst's len is long enough to store the
// formatted buffer. Uses specifiers in fmt to discover how many variadic
// arguments were passed, and walks up the stack to retrieve them.
// On success returns the number of bytes that were written into dst.
// Returns -1 if dst is not long enough.
// NOTE: This function must _not_ be inlined, otherwise the stack walking method
// breaks.
__attribute__((__cdecl__, noinline))
int klib_snprintf(char *dst, size_t len, const char *fmt, ...);
