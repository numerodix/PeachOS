#pragma once

#include <stdint.h>


// Returns the base^exponent. If the result overflows uint32_t, it returns 0.
uint32_t klib_u32_pow(uint32_t base, uint32_t exponent);

// Returns the base2 logarithm of number as an integer. If number is 0 it
// returns UINT32_MAX.
uint32_t klib_u32_log2(uint32_t number);

// Returns the base10 logarithm of number as an integer. If number is 0 it
// returns UINT32_MAX.
uint32_t klib_u32_log10(uint32_t number);

// Returns the base16 logarithm of number as an integer. If number is 0 it
// returns UINT32_MAX.
uint32_t klib_u32_log16(uint32_t number);
