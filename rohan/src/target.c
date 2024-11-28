#include "target.h"

#include <stdlib.h>

#include "log.h"
#include "types.h"

b8 CreateRenderTargetConfig(u32 w, u32 h, PixelLayout layout, RenderTargetConfig* conf) {
    if (!conf) {
        LERROR("Can't create render target configuration; null output pointer.");
        return false;
    }

    u8 stride = DEFAULT_PIXEL_LAYOUT;
    switch (layout) {
    case RGB888: stride = 3; break;
    case RGBA8888:
    case ARGB8888: stride = 4; break;

    default:
        LERROR(
            "Invalid render target pixel layout enumeration, using default (%s).",
            DEFAULT_PIXEL_LAYOUT
        );
    }

    u64 pitch = stride * w;
    *conf     = (RenderTargetConfig
    ){ .res = w * h, .pitch = pitch, .w = w, .h = h, .layout = layout, .stride = stride };

    return true;
}

b8 CreateRenderTarget(RenderTargetConfig conf, RenderTarget* target) {
    if (!target) {
        LERROR("Can't create render target; null output pointer.");
        return false;
    }

    void* buf = calloc(conf.res, conf.stride);
    if (!buf) {
        LERROR("Can't create render target; can't allocate memory for framebuffer.");
        return false;
    }

    *target = (RenderTarget){ .conf = conf, .buffer = buf };

    return true;
}

void DestroyRenderTarget(RenderTarget* target) { free(target->buffer); }
