#include "window.h"

#include <SDL.h>

#include "systems/logging.h"
#include "types.h"

b8 SetupWindow(WindowState* State, const WindowConfig* Conf) {
    if (!State) {
        LFATAL("Can't setup app window, NULL output window state.");
        return false;
    }

    if (!Conf) {
        State->Conf = (WindowConfig){ "SR1", 1440 * 900, 1440, 900, 1, 1 };
    } else {
        State->Conf = *Conf;
    }

    State->Handle = SDL_CreateWindow(
        State->Conf.Title, State->Conf.x, State->Conf.y, State->Conf.Width, State->Conf.Height, 0
    );
    State->Ren   = SDL_CreateRenderer(State->Handle, -1, SDL_RENDERER_ACCELERATED);
    State->Frame = SDL_CreateTexture(
        State->Ren, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, State->Conf.Width,
        State->Conf.Height
    );

    u32* _BufferMem   = calloc(State->Conf.Res * 2, sizeof(u32));
    State->Buffers[0] = (u8*)(_BufferMem);
    State->Buffers[1] = (u8*)(_BufferMem + State->Conf.Res);

    return true;
}

void ShutdownWindow(WindowState* State) {
    SDL_DestroyTexture(State->Frame);
    SDL_DestroyRenderer(State->Ren);
    SDL_DestroyWindow(State->Handle);
    State->Conf.Title = NULL;

    free(State->Buffers[0]);
}
