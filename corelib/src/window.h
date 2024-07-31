#ifndef WINDOW_H
#define WINDOW_H

#include <pthread.h>
#include <stdatomic.h>

#include "types.h"

typedef struct WindowConfig {
    const char* title;
    u64         res;
    u64         pitch;
    u32         w, h;
    u32         x, y;
} WindowConfig;

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

typedef struct WindowState {
    struct SDL_Window*   handle;
    struct SDL_Renderer* ren;
    struct SDL_Texture*  frame;
    WindowConfig         conf;
    u8*                  bufs[3]; // bufs[2] is arena memory
} WindowState;

b8   SetupWindow(WindowState* out_state, const WindowConfig* conf);

void ShutdownWindow(WindowState* state);

void UpdateWindow(WindowState* state);

void SwapBuffers(WindowState* state);

#endif
