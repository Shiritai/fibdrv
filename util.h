#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdint.h>
#include <stdio.h>

#define __CZ_MAX_ONES 0xFFFFFFFFFFFFFFFF
#define __clz(type, fn_postfix, bit_len, ones) \
    static int clz_##fn_postfix(type x)        \
    {                                          \
        if (!x)                                \
            return bit_len;                    \
        int bits = 0;                          \
        int shift = bit_len >> 1;              \
        type mask = (type) (ones << shift);    \
        while (shift) {                        \
            if (!(x & mask)) {                 \
                bits += shift;                 \
                x <<= shift;                   \
            }                                  \
            shift >>= 1;                       \
            mask <<= shift;                    \
        }                                      \
        return bits;                           \
    }
#define __ctz(type, fn_postfix, bit_len, ones) \
    static int ctz_##fn_postfix(type x)        \
    {                                          \
        if (!x)                                \
            return bit_len;                    \
        int bits = 0;                          \
        int shift = bit_len >> 1;              \
        type mask = (type) ~(ones << shift);   \
        while (shift) {                        \
            if (!(x & mask)) {                 \
                bits += shift;                 \
                x >>= shift;                   \
            }                                  \
            shift >>= 1;                       \
            mask >>= shift;                    \
        }                                      \
        return bits;                           \
    }

/**
 * Macro to generate "count leading zeros"
 * for type which length is less than int_64_t
 * Named: clz_"fn_postfix"
 */
#define clz(type, fn_postfix) \
    __clz(type, fn_postfix, (sizeof(type) * 8), __CZ_MAX_ONES)

/**
 * Macro to generate "count trailing zeros"
 * for type which length is less than int_64_t
 * Named: ctz_"fn_postfix"
 */
#define ctz(type, fn_postfix) \
    __ctz(type, fn_postfix, (sizeof(type) * 8), __CZ_MAX_ONES)

#define __LL long long
clz(__LL, long_long);  // clz_long_long
ctz(__LL, long_long);  // clz_long_long
#undef __LL            // clear __LL

/* Uncomment below to use clz/ctz functions */

// clz(int, int);         // clz_int
// clz(short, short);     // clz_short
// clz(char, char);       // clz_char
// clz(int8_t, int8);     // clz_int8
// clz(int16_t, int16);   // clz_int16
// clz(int32_t, int32);   // clz_int32
// clz(int64_t, int64);   // clz_int64
// clz(uint8_t, uint8);   // clz_uint8
// clz(uint16_t, uint16); // clz_uint16
// clz(uint32_t, uint32); // clz_uint32
// clz(uint64_t, uint64); // clz_uint64

// ctz(int, int);         // ctz_int
// ctz(short, short);     // ctz_short
// ctz(char, char);       // ctz_char
// ctz(int8_t, int8);     // ctz_int8
// ctz(int16_t, int16);   // ctz_int16
// ctz(int32_t, int32);   // ctz_int32
// ctz(int64_t, int64);   // ctz_int64
// ctz(uint8_t, uint8);   // ctz_uint8
// ctz(uint16_t, uint16); // ctz_uint16
// ctz(uint32_t, uint32); // ctz_uint32
// ctz(uint64_t, uint64); // ctz_uint64

#endif /* __UTIL_H__ */