#pragma once

#include <stdint.h>


// Formats the input number, interpreted as a size in bytes, in a human readable
// representation. The input is a u64 number split across two u32 inputs
// size_high and size_low.
// Returns 0 on success and populates dst.
// Returns 1 if dst is not long enough.
int klib_format_bytesize(uint32_t size_high, uint32_t size_low, char* dst, uint32_t len);
