#ifndef VEC3F_H
#define VEC3F_H

#include <x86intrin.h>

#include "../m128f.h"
#include "../types.h"

typedef struct {
    union {
        __m128 v;

        struct {
            f32 x, y, z, __w;
        };
    };
} mvec3f;

minline void   mstore3f(f32* _addr, mvec3f _v) { _vecm128f_Store(_addr, _v.v); }

minline void   mstream3f(void* _addr, mvec3f _v) { _vecm128f_Stream(_addr, _v.v); }

minline mvec3f mmax3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Max(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mmin3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Min(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mpack3f(f32 _x, f32 _y, f32 _z) {
    return (mvec3f){ .v = _vecm128f_Pack(_x, _y, _z, 0.f) };
}

minline mvec3f mset3f(f32 _s) { return (mvec3f){ .v = _vecm128f_Set(_s) }; }

minline mvec3f mzeros3f(void) { return (mvec3f){ .v = _vecm128f_Zeros() }; }

minline i32    mmovemask3f(mvec3f _v) { return _vecm128f_Movemask(_v.v); }

minline mvec3f mand3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_And(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mnand3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Nand(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mor3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Or(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mxor3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Xor(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mload3f(const f32* _addr) { return (mvec3f){ .v = _vecm128f_Load(_addr) }; }

minline mvec3f mloadone3f(const f32* _addr) { return (mvec3f){ .v = _vecm128f_Load1(_addr) }; }

minline mvec3f mundef3f(void) { return (mvec3f){ .v = _vecm128f_Undef() }; }

minline mvec3f minv3f(mvec3f _v) {
    _v.v = _vecm128f_Inv(_v.v);
    return _v;
}

minline mvec3f minvsqrt3f(mvec3f _v) {
    _v.v = _vecm128f_InvSqrt(_v.v);
    return _v;
}

minline mvec3f msqrt3f(mvec3f _v) {
    _v.v = _vecm128f_Sqrt(_v.v);
    return _v;
}

minline f32    mtofloat3f(mvec3f _v) { return _vecm128f_ToFloat(_v.v); }

minline mvec3f mequal3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Equal(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mnoteq3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_NotEq(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mgreateq3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_GreatEq(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mgreater3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Greater(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mlesseq3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_LessEq(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mless3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Less(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f madd3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Add(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f msub3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Sub(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mmul3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Mul(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mdiv3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_Div(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f maddsub3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_AddSub(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mhadd3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_HoriAdd(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mhsub3f(mvec3f _v0, mvec3f _v1) {
    _v0.v = _vecm128f_HoriSub(_v0.v, _v1.v);
    return _v0;
}

minline mvec3f mmaskblend3f(mvec3f _v0, mvec3f _v1, mvec3f _mask) {
    _v0.v = _vecm128f_MaskBlend(_v0.v, _v1.v, _mask.v);
    return _v0;
}

minline mvec3f mceil3f(mvec3f _v) {
    _v.v = _vecm128f_Ceil(_v.v);
    return _v;
}

minline mvec3f mfloor3f(mvec3f _v) {
    _v.v = _vecm128f_Floor(_v.v);
    return _v;
}

#define mblend3f(_v0, _v1, _ctrl)                                                                  \
    (mvec3f) { .v = _vecm128f_Blend(_v0.v, _v1.v, _ctrl) }

#define mextract3f(_v, _ctrl) _vecm128f_Extract(_v.v, _ctrl)

#define minsert3f(_v0, _v1, _ctrl)                                                                 \
    (mvec3f) { .v = _vecm128f_Insert(_v0.v, _v1.v, _ctrl) }

#define mround3f(_v, _round)                                                                       \
    (mvec3f) { .v = _vecm128f_Round(_v.v, _round) }

#define mshuffle3f(_v, _x, _y, _z)                                                                 \
    (mvec3f) { .v = _vecm128f_Shuffle(_v.v, _x, _y, _z, 3) }

#define mpermute3f(_v, _ctrl)                                                                      \
    (mvec3f) { .v = _vecm128f_Permute(_v.v, _ctrl) }

#define mcomp3f(_v0, _v1, _ctrl)                                                                   \
    (mvec3f) { .v = _vecm128f_Cmp(_v0.v, _v1.v, _ctrl) }

#define mgather3f(_addr, _idx, _scale)                                                             \
    (mvec3f) { .v = _vecm128f_Gather(_addr, _idx, _scale) }

#define mmaskgather3f(_src, _addr, _idx, _mask, _scale)                                            \
    (mvec3f) { .v = _vecm128f_MaskGather(_src.v, _addr, _idx, _mask.v, _scale) }

#if defined(__SSE4_1__) && VECM_USE_BUILTIN_DOT
minline f32 mdot3f(mvec3f _v0, mvec3f _v1) { return _vecm128f_Dot(_v0.v, _v1.v); }
#else
minline f32 mdot3f(mvec3f _v0, mvec3f _v1) {
    __m128 v    = _vecm128f_Mul(_v0.v, _v1.v);
    __m128 shuf = _vecm128f_Shuffle(v, 1, 0, 3, 2);
    __m128 sums = _vecm128f_Add(v, shuf);
    shuf        = _mm_movehl_ps(shuf, sums);
    sums        = _mm_add_ss(sums, shuf);
    return _vecm128f_ToFloat(sums);
}
#endif

minline void mmaskstore3f(f32* _addr, __m128i _mask, mvec3f _v) {
    _vecm128f_MaskStore(_addr, _mask, _v.v);
}

minline mvec3f mmaskload3f(const f32* _addr, __m128i _mask) {
    return (mvec3f){ .v = _vecm128f_MaskLoad(_addr, _mask) };
}

minline mvec3f mcross3f(mvec3f _v0, mvec3f _v1) {
    __m128 _x1 = _vecm128f_Shuffle(_v0.v, 1, 2, 0, 3);
    __m128 _x2 = _vecm128f_Shuffle(_v0.v, 2, 0, 1, 3);
    __m128 _y1 = _vecm128f_Shuffle(_v1.v, 2, 0, 1, 3);
    __m128 _y2 = _vecm128f_Shuffle(_v1.v, 1, 2, 0, 3);

    _v0.v      = _vecm128f_Sub(_vecm128f_Mul(_x1, _y1), _vecm128f_Mul(_x2, _y2));
    return _v0;
}

f32            sqrtf(f32);

minline f32    mlen3f(mvec3f _v) { return sqrtf(mdot3f(_v, _v)); }

minline mvec3f mnorm3f(mvec3f _v) {
    _v.v = _vecm128f_Div(_v.v, _mm_set1_ps(mlen3f(_v)));
    return _v;
}

#endif
