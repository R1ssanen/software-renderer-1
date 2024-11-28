#ifndef _TARGET_H_
#define _TARGET_H_

#include "api.h"
#include "types.h"

typedef enum { RGB888, RGBA8888, ARGB8888 } PixelLayout;

#define DEFAULT_PIXEL_LAYOUT RGB888

typedef struct RenderTargetConfig {
    u64         res;
    u64         pitch;
    u32         w, h;
    PixelLayout layout;
    u8          stride;
} RenderTargetConfig;

b8 RHAPI CreateRenderTargetConfig(u32 w, u32 h, PixelLayout layout, RenderTargetConfig* conf);

typedef struct RenderTarget {
    RenderTargetConfig conf;
    void*              buffer;
} RenderTarget;

b8 RHAPI   CreateRenderTarget(RenderTargetConfig conf, RenderTarget* target);

void RHAPI DestroyRenderTarget(RenderTarget* target);

#endif
