#ifndef RENDER_H
#define RENDER_H

#include <math.h>

#include "math/vertex.h"
#include "systems/logging.h"
#include "types.h"
#include "vecm/vec/vec3f.h"
#include "window.h"

static inline f32 Edge(f32 ax, f32 ay, f32 bx, f32 by, f32 cx, f32 cy) {
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

static void RenderTriangle(
    WindowState* restrict win, Vertex* restrict a, Vertex* restrict b, Vertex* restrict c
);

#include "shading/test_shader.h"

static inline void Render(WindowState* restrict win) {
    Vertex a = { .pos = mpack3f(0, 0, 0), .color = mpack3f(255, 0, 0), .uv = mpack2f(0, 0) };
    Vertex b = { .pos = mpack3f(1, 1, 0), .color = mpack3f(0, 255, 0), .uv = mpack2f(1, 1) };
    Vertex c = { .pos = mpack3f(0, 1, 0), .color = mpack3f(0, 0, 255), .uv = mpack2f(0, 1) };
    Vertex d = { .pos = mpack3f(1, 0, 0), .color = mpack3f(255, 255, 0), .uv = mpack2f(1, 0) };

    a.pos[0] *= win->conf.w - 0.5f, a.pos[1] *= win->conf.h - 0.5f;
    b.pos[0] *= win->conf.w - 0.5f, b.pos[1] *= win->conf.h - 0.5f;
    c.pos[0] *= win->conf.w - 0.5f, c.pos[1] *= win->conf.h - 0.5f;
    d.pos[0] *= win->conf.w - 0.5f, d.pos[1] *= win->conf.h - 0.5f;

    RenderTriangle(win, &a, &b, &c);
    RenderTriangle(win, &a, &d, &b);
}

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

static u8*         s_tex;

static inline void LoadTexture(void) {
    i32 w, h, channels;
    s_tex = stbi_load("texture.png", &w, &h, &channels, 0);

    if (!s_tex) { LFATAL(stbi_failure_reason()); }
}

static inline f32 clamp(f32 _n, f32 min, f32 max) {
    const f32 t = _n < min ? min : _n;
    return t > max ? max : t;
}

static b8   lessThanZero(mvec3f _a) { return mmovemask3f(mless3f(_a, mzeros3f())); }

static void RenderTriangle(
    WindowState* restrict win, Vertex* restrict a, Vertex* restrict b, Vertex* restrict c
) {
    mvec3f rp = mpack3f(a->color[0], b->color[0], c->color[0]),
           gp = mpack3f(a->color[1], b->color[1], c->color[1]),
           bp = mpack3f(a->color[2], b->color[2], c->color[2]);

    mvec3f up = mpack3f(a->uv[0], b->uv[0], c->uv[0]), vp = mpack3f(a->uv[1], b->uv[1], c->uv[1]);

    f32    minx = fminf(a->pos[0], fminf(b->pos[0], c->pos[0])),
        miny    = fminf(a->pos[1], fminf(b->pos[1], c->pos[1]));
    f32 maxx    = fmaxf(a->pos[0], fmaxf(b->pos[0], c->pos[0])),
        maxy    = fmaxf(a->pos[1], fmaxf(b->pos[1], c->pos[1]));

    mvec3f dx   = mpack3f(a->pos[1] - b->pos[1], b->pos[1] - c->pos[1], c->pos[1] - a->pos[1]),
           dy   = mpack3f(-a->pos[0] + b->pos[0], -b->pos[0] + c->pos[0], -c->pos[0] + a->pos[0]);

    f32    d    = 1.f / Edge(a->pos[0], a->pos[1], b->pos[0], b->pos[1], c->pos[0], c->pos[1]);
    mvec3f b0   = mpack3f(
        Edge(a->pos[0], a->pos[1], b->pos[0], b->pos[1], minx, miny),
        Edge(b->pos[0], b->pos[1], c->pos[0], c->pos[1], minx, miny),
        Edge(c->pos[0], c->pos[1], a->pos[0], a->pos[1], minx, miny)
    );

    u8* row    = win->bufs[0] + (u64)(miny * win->conf.w + minx) * sizeof(u32);
    u32 rpitch = (u64)(maxx - minx) * sizeof(u32);

    for (u64 y = (u64)(miny); y <= (u64)(maxy); ++y) {
        mvec3f b1 = b0;
        for (u8* p = row; (p - row) <= rpitch; p += sizeof(u32)) {

            if (lessThanZero(b1)) {
            } else {
                mvec3f bc = mmul3f(b1, mset3f(d));
                bc        = mshuffle3f(bc, 1, 2, 0);

                //*(u32*)p =
                //    ((u32*)s_tex)[(u64)(320 * mdot3f(vp, bc)) * 320 + (u64)(320 * mdot3f(up,
                //    bc))];

                *p        = (u8)(mdot3f(rp, bc));
                *(p + 1)  = (u8)(mdot3f(gp, bc));
                *(p + 2)  = (u8)(mdot3f(bp, bc));
            }

            b1 = madd3f(b1, dx);
        }

        b0 = madd3f(b0, dy);
        row += win->conf.pitch;
    }
}

#endif
