#include "render.h"

#include <math.h>
#include <vecm/vec/vec3f.h>

#include "target.h"

f32 Edge(f32 ax, f32 ay, f32 bx, f32 by, f32 cx, f32 cy) {
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

b8   LessThanZero(mvec3f _a) { return mmovemask3f(mless3f(_a, mzeros3f())); }

void RenderTriangle(RenderTarget* tg, u32 (*shade)(u64, f32*), mvec3f* a, mvec3f* b, mvec3f* c) {
    mvec3f zpack = mpack3f(a->z, b->z, c->z);

    f32    minx = fminf(a->x, fminf(b->x, c->x)), miny = fminf(a->y, fminf(b->y, c->y));
    f32    maxx = fmaxf(a->x, fmaxf(b->x, c->x)), maxy = fmaxf(a->y, fmaxf(b->y, c->y));

    mvec3f dx = mpack3f(b->y - c->y, c->y - a->y, a->y - b->y),
           dy = mpack3f(-b->x + c->x, -c->x + a->x, -a->x + b->x);

    f32    d  = 1.f / Edge(a->x, a->y, b->x, b->y, c->x, c->y);
    mvec3f b0 = mpack3f(
        Edge(b->x, b->y, c->x, c->y, minx, miny), Edge(c->x, c->y, a->x, a->y, minx, miny),
        Edge(a->x, a->y, b->x, b->y, minx, miny)
    );

    u32* framebuf = (u32*)tg->buffer;

    u64  row      = 0;
    for (f32 y = miny; y <= maxy; ++y) {
        mvec3f b1 = b0;

        for (f32 x = minx; x <= maxx; ++x) {
            if (LessThanZero(b1)) {
            } else {
                mvec3f bc              = mmul3f(b1, mset3f(d));
                f32    z               = mdot3f(zpack, bc);

                // bc                     = mshuffle3f(bc, 1, 2, 0);
                framebuf[row + (u64)x] = shade(row + (u64)x, (f32[3]){ bc.x, bc.y, bc.z });
            }

            b1 = madd3f(b1, dx);
        }

        b0 = madd3f(b0, dy);
        row += tg->conf.w;
    }
}

#include <dlfcn.h>

#include "shader.h"

typedef struct {
    void* handle;
    ShaderModule* (*get_module)(void);
} Shader;

Shader LoadShader(const char* file) {
    void* handle = dlopen(file, RTLD_LAZY);
    if (!handle) { return (Shader){ 0 }; }

    return (Shader){ handle, (ShaderModule * (*)(void)) dlsym(handle, "GetShaderModule") };
}

#include <string.h>

void DrawElementsTriangle(RenderTarget* tg, const ElementBuffer* _ebo) {

    ElementBuffer* ebo = malloc(sizeof(ElementBuffer));
    memcpy(ebo, _ebo, sizeof(ElementBuffer));

    Shader        vert            = LoadShader("sandbox/shaders/libvs.so");
    ShaderModule* module          = vert.get_module();

    u64           element_stride  = _ebo->prim_size * _ebo->prims_per_elem;
    u64           elements_stride = _ebo->prim_size * _ebo->prim_count;

    for (u64 byte = 0; byte < elements_stride; byte += element_stride) {
        module->_vmain(byte / element_stride, (u8*)(ebo->prims) + byte);
    }

    dlclose(vert.handle);

    Shader frag = LoadShader("sandbox/shaders/libfs.so");
    module      = frag.get_module();

    u8* prims   = ebo->prims;
    for (u64 i = 0; i < _ebo->id_count; i += 3) {
        RenderTriangle(
            tg, module->_fmain, (mvec3f*)(prims + ebo->ids[i] * element_stride),
            (mvec3f*)(prims + ebo->ids[i + 1] * element_stride),
            (mvec3f*)(prims + ebo->ids[i + 2] * element_stride)
        );
    }

    dlclose(frag.handle);
    free(ebo);
}
