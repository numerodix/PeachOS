// A statically allocated byte array with a fixed capacity that performs bounds
// checks - essentially a fancy wrapper around a uint8_t[].

#pragma once

#include <stddef.h>
#include <stdint.h>


// Creates a byte array on the stack (or in static memory) bound to varname,
// with storage_buffer as its backing storage.
#define CREATE_BYTE_ARRAY(varname, storage_buffer)                      \
    klib_byte_array_t __##varname = {                                   \
        .at = __klib_byte_array_at,                                     \
        .cap = __klib_byte_array_cap,                                   \
        .clear = __klib_byte_array_clear,                               \
        .push = __klib_byte_array_push,                                 \
        .size = __klib_byte_array_size,                                 \
                                                                        \
        ._storage = storage_buffer,                                     \
        ._cap = sizeof(storage_buffer),                                 \
        ._size = 0,                                                     \
    };                                                                  \
    klib_byte_array_t *varname = &__##varname;


typedef struct _klib_byte_array klib_byte_array_t;

struct _klib_byte_array {
    // Returns the array element at pos, in byte. Returns 0 on success, returns
    // 1 on out of bounds access.
    int (*at)(klib_byte_array_t *array, size_t pos, uint8_t *byte);

    // Returns the static capacity of the array.
    size_t (*cap)(klib_byte_array_t *array);

    // Resets the size of the array to zero. All existing elements are rendered
    // inaccessible.
    void (*clear)(klib_byte_array_t *array);

    // Appends an element to the array. Returns 0 on success, returns 1 if the
    // array does not have sufficient capacity.
    int (*push)(klib_byte_array_t *array, uint8_t byte);

    // Returns the current size of the array, which reflects the number of
    // elements that have been pushed.
    size_t (*size)(klib_byte_array_t *array);

    uint8_t *_storage;
    size_t _cap;
    size_t _size;
};


int __klib_byte_array_at(klib_byte_array_t *array, size_t pos, uint8_t *byte);

size_t __klib_byte_array_cap(klib_byte_array_t *array);

void __klib_byte_array_clear(klib_byte_array_t *array);

int __klib_byte_array_push(klib_byte_array_t *array, uint8_t byte);

size_t __klib_byte_array_size(klib_byte_array_t *array);
