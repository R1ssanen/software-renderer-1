#ifndef _SHADER_H_
#define _SHADER_H_

#include "log.h"
#include "types.h"

enum shader_t {
    VERTEX_SHADER,
    FRAGMENT_SHADER,
};

typedef struct {
    void* uniforms[128];

    union {
        u32 (*_fmain)(u64, f32*);
        void (*_vmain)(u64, void*);
    };

    enum shader_t is;
} ShaderModule;

ShaderModule* GetShaderModule(void);

#define FRAGMENT_MODULE(version)                                                                   \
    static u32          _frags_main(u64, f32*);                                                    \
    static ShaderModule module = { ._fmain = _frags_main, .is = FRAGMENT_SHADER };                 \
    ShaderModule*       GetShaderModule(void) { return &module; }

#define VERTEX_MODULE(version)                                                                     \
    static void         _verts_main(u64, void*);                                                   \
    static ShaderModule module = { ._vmain = _verts_main, .is = VERTEX_SHADER };                   \
    ShaderModule*       GetShaderModule(void) { return &module; }

#define LOCATION(type, name, offset)                                                               \
    static type* name(void) {                                                                      \
        if (!ELEMENT) LFATAL("Access of null element.");                                           \
        return (type*)(ELEMENT) + offset;                                                          \
    }

#define UNIFORM(type, name, offset)                                                                \
    static type name(void) {                                                                       \
        if (!module.uniforms[offset]) LFATAL("Access of null uniform.");                           \
        return *(type*)module.uniforms[offset];                                                    \
    }

#define fmain() _frags_main(u64 ID, f32* BARYCOORD)

#define vmain() _verts_main(u64 ID, void* ELEMENT)

#endif
