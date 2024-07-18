#include <SDL.h>

#include "systems/input.h"
#include "systems/logging.h"
#include "types.h"

/*#define setr(_buf, _loc, _val) _buf[_loc + 0] = _val
#define setg(_buf, _loc, _val) _buf[_loc + 1] = _val
#define setb(_buf, _loc, _val) _buf[_loc + 2] = _val
#define seta(_buf, _loc, _val) _buf[_loc + 3] = _val
#define setp(_buf, _loc, _val) *(u32*)(_buf + _loc) = _val
*/

i32 main(unused i32 argc, unused char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        LFATAL("Failed to init SDL.");
        return -1;
    }

    if (!InitSystemInput()) { return 1; }

    LDEBUG("Engine systems initialized.");

    /*SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    DM.format         = SDL_PIXELFORMAT_RGBA32;
    SDL_Window*   Win = SDL_CreateWindow("SR1", 0, 0, 1440, 900, 0);
    SDL_Renderer* Ren = SDL_CreateRenderer(Win, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture*  Buf =
        SDL_CreateTexture(Ren, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, 720, 450);

    u32*    __Arena    = calloc(720 * 450 * 2, sizeof(u32));
    u8*     Buffers[2] = { (u8*)(__Arena), (u8*)(__Arena + 720 * 450) };

    clock_t Start      = clock();
    u32     Frames     = 0;
    for (const u8* Keys = SDL_GetKeyboardState(NULL); !Keys[SDL_SCANCODE_Q];
         SDL_PumpEvents(), ++Frames) {

        for (u64 y = 0; y < 450; ++y) {
            for (u64 x = 0; x < 720; ++x) {
                u64 l = (y * 720 + x) * 4;

                setr(Buffers[0], l, (u8)(0xFF * (x / 720.f)));
                setg(Buffers[0], l, (u8)(0xFF * (y / 450.f)));
                setb(Buffers[0], l, (u8)(0xFF * (sinf(Frames / 50.f) * 0.5f + 0.5f)));
                seta(Buffers[0], l, 0xFF);
            }
        }

        // swap buffers
        u8* _Tmp   = Buffers[1];
        Buffers[1] = Buffers[0];
        Buffers[0] = _Tmp;

        SDL_UpdateTexture(Buf, NULL, Buffers[0], 720 * sizeof(u32));
        SDL_RenderCopy(Ren, Buf, NULL, NULL);
        SDL_RenderPresent(Ren);
    }

    f64 RuntimeS = (f64)(clock() - Start) / CLOCKS_PER_SEC;
    LINFO("%g ms/frame", (RuntimeS * 1000) / (f64)(Frames));
    LINFO("%u FPS", (u32)(Frames / RuntimeS));

    free(__Arena);
    return 0;*/
}
