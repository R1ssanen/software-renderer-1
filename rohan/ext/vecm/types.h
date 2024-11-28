/**
 * @file types.h
 * @brief Convenience type definitions.
 * @author github.com/r1ssanen
 */

#ifndef TYPES_H
#define TYPES_H

#define true  1
#define false 0

typedef _Bool         b8;

typedef signed char   i8;
typedef signed int    i32;
typedef signed long   i64;
typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned long u64;

typedef float         f32;
typedef double        f64;

#define minline           static inline __attribute__((always_inline))
#define unused            __attribute__((unused))

#define DO_PRAGMA(_str)   _Pragma(#_str)
#define VM_ERROR(_errmsg) DO_PRAGMA(GCC error #_errmsg)

#endif
