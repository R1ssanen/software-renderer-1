#ifndef VEC4f_H
#define VEC4f_H

#include <x86intrin.h>

#include "../m128f.h"
#include "../types.h"

typedef struct {
    union {
        __m128 v;

        struct {
            f32 x, y, z, w;
        };
    };
} mvec4f;

minline void   mstore4f(f32* _addr, mvec4f _v) { _vecm128f_Store(_addr, _v.v); }

minline void   mstream4f(void* _addr, mvec4f _v) { _vecm128f_Stream(_addr, _v.v); }

minline mvec4f mmax4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Max(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mmin4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Min(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mpack4f(f32 _x, f32 _y, f32 _z, f32 _w) {
    return (mvec4f){ .v = _vecm128f_Pack(_x, _y, _z, _w) };
}

minline mvec4f mset4f(f32 _s) { return (mvec4f){ .v = _vecm128f_Set(_s) }; }

minline mvec4f mzeros4f(void) { return (mvec4f){ .v = _vecm128f_Zeros() }; }

minline i32    mmovemask4f(mvec4f _v) { return _vecm128f_Movemask(_v.v); }

minline mvec4f mand4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_And(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mnand4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Nand(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mor4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Or(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mxor4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Xor(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mload4f(const f32* _addr) { return (mvec4f){ .v = _vecm128f_Load(_addr) }; }

minline mvec4f mloadone4f(const f32* _addr) { return (mvec4f){ .v = _vecm128f_Load1(_addr) }; }

minline mvec4f mundef4f(void) { return (mvec4f){ .v = _vecm128f_Undef() }; }

minline mvec4f minv4f(mvec4f _v) {
    _v.v = _vecm128f_Inv(_v.v);
    return _v;
}

minline mvec4f minvsqrt4f(mvec4f _v) {
    _v.v = _vecm128f_InvSqrt(_v.v);
    return _v;
}

minline mvec4f msqrt4f(mvec4f _v) {
    _v.v = _vecm128f_Sqrt(_v.v);
    return _v;
}

minline f32    mtofloat4f(mvec4f _v) { return _vecm128f_ToFloat(_v.v); }

minline mvec4f mequal4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Equal(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mnoteq4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_NotEq(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mgreateq4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_GreatEq(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mgreater4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Greater(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mlesseq4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_LessEq(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mless4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Less(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f madd4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Add(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f msub4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Sub(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mmul4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Mul(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mdiv4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_Div(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f maddsub4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_AddSub(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mhadd4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_HoriAdd(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mhsub4f(mvec4f _v0, mvec4f _v1) {
    _v0.v = _vecm128f_HoriSub(_v0.v, _v1.v);
    return _v0;
}

minline mvec4f mmaskblend4f(mvec4f _v0, mvec4f _v1, mvec4f _mask) {
    _v0.v = _vecm128f_MaskBlend(_v0.v, _v1.v, _mask.v);
    return _v0;
}

minline mvec4f mceil4f(mvec4f _v) {
    _v.v = _vecm128f_Ceil(_v.v);
    return _v;
}

minline mvec4f mfloor4f(mvec4f _v) {
    _v.v = _vecm128f_Floor(_v.v);
    return _v;
}

#define mblend4f(_v0, _v1, _ctrl)                                                                  \
    (mvec4f) { .v = _vecm128f_Blend(_v0.v, _v1.v, _ctrl) }

#define mextract4f(_v, _ctrl) _vecm128f_Extract(_v.v, _ctrl)

#define minsert4f(_v0, _v1, _ctrl)                                                                 \
    (mvec4f) { .v = _vecm128f_Insert(_v0.v, _v1.v, _ctrl) }

#define mround4f(_v, _round)                                                                       \
    (mvec4f) { .v = _vecm128f_Round(_v.v, _round) }

#define mshuffle4f(_v, _x, _y, _z, _w)                                                             \
    (mvec4f) { .v = _vecm128f_Shuffle(_v.v, _x, _y, _z, _w) }

#define mpermute4f(_v, _ctrl)                                                                      \
    (mvec4f) { .v = _vecm128f_Permute(_v.v, _ctrl) }

#define mcomp4f(_v0, _v1, _ctrl)                                                                   \
    (mvec4f) { .v = _vecm128f_Cmp(_v0.v, _v1.v, _ctrl) }

#define mgather4f(_addr, _idx, _scale)                                                             \
    (mvec4f) { .v = _vecm128f_Gather(_addr, _idx, _scale) }

#define mmaskgather4f(_src, _addr, _idx, _mask, _scale)                                            \
    (mvec4f) { .v = _vecm128f_MaskGather(_src.v, _addr, _idx, _mask.v, _scale) }

#if defined(__SSE4_1__) && VECM_USE_BUILTIN_DOT
minline f32 mdot4f(mvec4f _v0, mvec4f _v1) { return _vecm128f_Dot(_v0.v, _v1.v); }
#else
minline f32 mdot4f(mvec4f _v0, mvec4f _v1) {
    __m128 v    = _vecm128f_Mul(_v0.v, _v1.v);
    __m128 shuf = _vecm128f_Shuffle(v, 1, 0, 3, 2);
    __m128 sums = _vecm128f_Add(v, shuf);
    shuf        = _mm_movehl_ps(shuf, sums);
    sums        = _mm_add_ss(sums, shuf);
    return _vecm128f_ToFloat(sums);
}
#endif

minline void mmaskstore4f(f32* _addr, __m128i _mask, mvec4f _v) {
    _vecm128f_MaskStore(_addr, _mask, _v.v);
}

minline mvec4f mmaskload4f(const f32* _addr, __m128i _mask) {
    return (mvec4f){ .v = _vecm128f_MaskLoad(_addr, _mask) };
}

minline mvec4f mcross4f(mvec4f _v0, mvec4f _v1) {
    __m128 _x1 = _vecm128f_Shuffle(_v0.v, 1, 2, 0, 3);
    __m128 _x2 = _vecm128f_Shuffle(_v0.v, 2, 0, 1, 3);
    __m128 _y1 = _vecm128f_Shuffle(_v1.v, 2, 0, 1, 3);
    __m128 _y2 = _vecm128f_Shuffle(_v1.v, 1, 2, 0, 3);

    _v0.v      = _vecm128f_Sub(_vecm128f_Mul(_x1, _y1), _vecm128f_Mul(_x2, _y2));
    return _v0;
}

f32            sqrtf(f32);

minline f32    mlen4f(mvec4f _v) { return sqrtf(mdot4f(_v, _v)); }

minline mvec4f mnorm4f(mvec4f _v) {
    _v.v = _vecm128f_Div(_v.v, _mm_set1_ps(mlen4f(_v)));
    return _v;
}

#endif
