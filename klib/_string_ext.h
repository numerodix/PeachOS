#pragma once

#include <stddef.h>
#include <stdint.h>


// Returns the decimal string representation of number in buf, where len is the
// length of buf. Returns 0 on success. Returns 1 if buf is not long enough.
int klib_u32tostr_dec(uint32_t number, char *buf, size_t len);

// Returns the hexadecimal string representation of number in buf, where len is
// the length of buf. Returns 0 on success. Returns 1 if buf is not long enough.
int klib_u32tostr_hex(uint32_t number, char *buf, size_t len);
