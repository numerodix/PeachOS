#pragma once

#include <stddef.h>


// Copies len number of bytes from src into dest. Note that src and dest must
// not overlap.
void *klib_memcpy(void *dest, const void *src, size_t len);

// Sets len n of bytes in s to c.
void klib_memset(void *s, int c, size_t n);

// Compares s1 and s2 for equality.
// Returns 0 if s1 and s2 are of equal length and contain the same bytes.
// Returns -1 if:
// - s1 is shorter than s2, or
// - the first non-equal byte in s1 is less than that in s2.
// Returns 1 if:
// - s1 is longer than s2, or
// - the first non-equal byte in s1 is greater than that in s2.
int klib_strcmp(const char *s1, const char *s2);

// Returns the number of characters in the string, before the null byte. Note
// that s must end in a null byte, otherwise we get a buffer overflow.
size_t klib_strlen(const char *s);
