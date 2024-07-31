#include "window.h"

#include <pthread.h>
#include <SDL.h>

#include "systems/logging.h"
#include "types.h"

b8 SetupWindow(WindowState* state, const WindowConfig* conf) {
    if (!state) {
        LFATAL("Can't setup app window, NULL output window state.");
        return false;
    }

    if (!conf) {
        state->conf = (WindowConfig){ .title = "SR1",
                                      .res   = 1440 * 900,
                                      .pitch = 1440 * sizeof(u32),
                                      .w     = 1440,
                                      .h     = 900,
                                      .x     = 1,
                                      .y     = 1 };
    } else {
        state->conf = *conf;
    }

    state->handle = SDL_CreateWindow(
        state->conf.title, state->conf.x, state->conf.y, state->conf.w, state->conf.h, 0
    );
    state->ren   = SDL_CreateRenderer(state->handle, -1, SDL_RENDERER_ACCELERATED);
    state->frame = SDL_CreateTexture(
        state->ren, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, state->conf.w,
        state->conf.h
    );

    state->bufs[2] = calloc(state->conf.res * 2, sizeof(u32));
    state->bufs[0] = (u8*)(state->bufs[2]);
    state->bufs[1] = (u8*)(state->bufs[2] + state->conf.res * sizeof(u32));

    return true;
}

void ShutdownWindow(WindowState* state) {
    SDL_DestroyTexture(state->frame);
    SDL_DestroyRenderer(state->ren);
    SDL_DestroyWindow(state->handle);
    state->conf.title = NULL;

    free(state->bufs[2]);
}

void UpdateWindow(WindowState* state) {
    // TODO: Add a custom update rect possibility
    SDL_UpdateTexture(state->frame, NULL, (void*)(state->bufs[1]), state->conf.pitch);
    SDL_RenderCopy(state->ren, state->frame, NULL, NULL);
    SDL_RenderPresent(state->ren);
}

void SwapBuffers(WindowState* state) {
    // swap buffers
    u8* tmp        = state->bufs[0];
    state->bufs[0] = state->bufs[1];
    state->bufs[1] = tmp;

    memset(state->bufs[0], 0, state->conf.res * sizeof(u32));
}
