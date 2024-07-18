#ifndef WINDOW_H
#define WINDOW_H

#include "types.h"

typedef struct WindowConfig {
    const char* Title;
    u64         Res;
    u32         Width;
    u32         Height;
    u32         x, y;
} WindowConfig;

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

typedef struct WindowState {
    struct SDL_Window*   Handle;
    struct SDL_Renderer* Ren;
    struct SDL_Texture*  Frame;
    WindowConfig         Conf;
    u8*                  Buffers[2];
} WindowState;

b8   SetupWindow(WindowState* OutState, const WindowConfig* Conf);

void ShutdownWindow(WindowState* State);

#endif
