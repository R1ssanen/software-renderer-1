#ifndef SHADER_H
#define SHADER_H

#include <string.h>

#include "../types.h"

static inline u64 Hash64(const char* _str) {
    u64 hash = 0xcbf29ce484222325;

    for (u64 i = 0; i < strlen(_str); ++i) {
        hash ^= _str[i];
        hash *= 0x100000001b3;
    }

    return hash;
}

#define SHADERMODULE(_name) static inline void _method_##_name(void)

typedef struct Shader {
    void (*method)(void);
} Shader;

struct ShaderState {
    Shader shaders[255];
    u64    shader_count;
};

extern struct ShaderState shader_state;

#define RegisterShader(_name)                                                                      \
    { shader_state[shader_state.shader_count++] = shader; }

#endif
