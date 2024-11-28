#include <rohan.h>
#include <SDL.h>
#include <vecm/vec/vec3f.h>

int main(int argc, char** argv) {
    LINFO("Starting Rohan sandbox.");

    RenderTargetConfig conf;
    if (!CreateRenderTargetConfig(1440, 900, RGBA8888, &conf)) {
        LFATAL("Could not create render target config.");
        return 1;
    }

    RenderTarget tg;
    if (!CreateRenderTarget(conf, &tg)) {
        LFATAL("Could not create render target.");
        return 1;
    }

    mvec3f prims[] = {
        mpack3f(0, 0, 0),
        mpack3f(conf.w - 1, 0, 0),
        mpack3f(conf.w - 1, conf.h - 1, 0),
        mpack3f(0, conf.h - 1, 0),
    };
    u64           ids[] = { 0, 1, 2, 0, 2, 3 };
    ElementBuffer ebo   = CreateElementBuffer(prims, 4, sizeof(f32), 4, ids, 6);

    DrawElementsTriangle(&tg, &ebo);

    SDL_Window* win = SDL_CreateWindow(
        "Rohan - Sandbox", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, conf.w, conf.h, 0
    );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture*  tex =
        SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, conf.w, conf.h);

    SDL_UpdateTexture(tex, NULL, tg.buffer, conf.pitch);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);

    scanf("exit with <enter>");

    DestroyRenderTarget(&tg);
    return 0;
}
