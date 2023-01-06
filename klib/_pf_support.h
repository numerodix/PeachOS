#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


enum __pf_specifier_length {
    __none = 0,

    // "hh": For integer types, causes printf to expect an int-sized integer
    // argument which was promoted from a char.
    __char,

    // "h": For integer types, causes printf to expect an int-sized integer
    // argument which was promoted from a short.
    __short,

    // "l": For integer types, causes printf to expect a long-sized integer
    // argument.
    __long,

    // "ll": For integer types, causes printf to expect a long long-sized
    // integer argument.
    __longlong,

    // "z": For integer types, causes printf to expect a size_t-sized integer
    // argument.
    __sizet,
};

// %[flags][width][.precision][length]type
struct __pf_specifier {
    // Flags

    // '-': Left-align the output of this placeholder. The default is to
    // right-align the output.
    bool left_align;

    // '+': Prepends a plus for positive signed-numeric types. positive '+',
    // negative '-'. The default doesn't prepend anything in front of positive
    // numbers.
    bool leading_plus;

    // ' ': Prepends a space for positive signed-numeric types. positive ' ',
    // negative '-'. This flag is ignored if the + flag exists. (The default
    // doesn't prepend anything in front of positive numbers.)
    bool leading_space;

    // '0': When the 'width' option is specified, prepends zeros for numeric
    // types. (The default prepends spaces.)
    bool leading_zeroes;

    // ''': The integer or exponent of a decimal has the thousands grouping
    // separator applied.
    bool thousand_grouping;

    // '#': For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to
    // non-zero numbers.
    bool leading_num_prefix;

    // Width

    // The width field specifies a /minimum/ number of characters to output. It
    // does not cause truncation of oversized fields.
    uint16_t width;

    // Precision

    // The precision field usually specifies a /maximum/ limit on the output,
    // depending on the particular formatting type.
    uint16_t precision;

    // Length
    enum __pf_specifier_length length;

    // Type

    // %:       Prints a literal % character (this type doesn't accept any
    // flags, width, precision, length fields).
    // d, i:    int as a signed integer. %d and %i are synonymous for output,
    // but are different when used with scanf for input (where using %i will
    // interpret a number as hexadecimal if it's preceded by 0x, and octal if
    // it's preceded by 0.)
    // u:       Print decimal unsigned int.
    // f, F:    double in normal (fixed-point) notation. f and F only differs in
    // how the strings for an infinite number or NaN are printed (inf, infinity
    // and nan for f; INF, INFINITY and NAN for F).
    // e, E:    double value in standard form (d.ddde±dd). An E conversion uses
    // the letter E (rather than e) to introduce the exponent. The exponent
    // always contains at least two digits; if the value is zero, the exponent
    // is 00. In Windows, the exponent contains three digits by default, e.g.
    // 1.5e002, but this can be altered by Microsoft-specific _set_output_format
    // function.
    // g, G:    double in either normal or exponential notation, whichever is
    // more appropriate for its magnitude. g uses lower-case letters, G uses
    // upper-case letters. This type differs slightly from fixed-point notation
    // in that insignificant zeroes to the right of the decimal point are not
    // included. Also, the decimal point is not included on whole numbers.
    // x, X:    unsigned int as a hexadecimal number. x uses lower-case letters
    // and X uses upper-case.
    // o:       unsigned int in octal.
    // s:       null-terminated string.
    // c:       char (character).
    // p:       void* (pointer to void) in an implementation-defined format.
    // a, A:    double in hexadecimal notation, starting with 0x or 0X. a uses
    // lower-case letters, A uses upper-case letters.[5][6] (C++11 iostreams
    // have a hexfloat that works the same).
    // n:       Print nothing, but writes the number of characters written so
    // far into an integer pointer parameter.
    uint8_t type;
};


// Parses the first specifier in the input str. Returns the number of bytes that
// were consumed.
size_t __parse_pf_specifier(const char *str, struct __pf_specifier *spec);
