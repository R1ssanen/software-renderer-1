#ifndef PACK_H
#define PACK_H

#include <x86intrin.h>

#include "types.h"

typedef __m64 m4x16;
typedef __m64 m8x8;

#define mpack4x16(_a, _b, _c, _d) _mm_set_pi16((i16)(_d), (i16)(_c), (i16)(_b), (i16)(_a))
#define mpack8x8(_a, _b, _c, _d, _e, _f, _g, _h)                                                   \
    _mm_set_pi8(                                                                                   \
        (char)(_h), (char)(_g), (char)(_f), (char)(_e), (char)(_d), (char)(_c), (char)(_b),        \
        (char)(_a)                                                                                 \
    )
#define mset2x32(_Val) _mm_set1_pi32(_Val)
#define mset4x16(_Val) _mm_set1_pi16(_Val)
#define mset8x8(_Val)  _mm_set1_pi8(_Val)
#define mzero64()      _mm_setzero_si64()

#endif
