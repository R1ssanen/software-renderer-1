#include "application.h"

#include "systems/input.h"
#include "systems/logging.h"
#include "types.h"
#include "window.h"

typedef struct AppState {
    WindowState win_state;
    b8          running;
    b8          no_focus;
} AppState;

static AppState s_state;
static b8       s_is_init = false;

b8              CreateApp(const WindowConfig* conf) {
    if (s_is_init) {
        LERROR("Double initialization of application.");
        return false;
    }

    if (!InitSystemInput()) {
        LERROR("Could not initialize input system.");
        return false;
    }

    if (!SetupWindow(&s_state.win_state, conf)) { return false; }
    s_state.running  = true;
    s_state.no_focus = false;
    s_is_init        = true;

    return true;
}

#include <time.h>

#include "render.h"
#include "shading/shader.h"
#include "shading/test_shader.h"

struct ShaderState shader_state;

b8                 RunApp(void) {
    clock_t start  = clock();
    u64     frames = 0;

    BindShader(test);
    shader_state.bound_method();

    LoadTexture();
    while (s_state.running) {
        PumpEvents();
        if (KeyDown(KC_Q)) { s_state.running = false; }

        Render(&s_state.win_state);

        UpdateWindow(&s_state.win_state);
        SwapBuffers(&s_state.win_state);
        ++frames;
    }

    f64 s_elapsed = (f64)(clock() - start) / CLOCKS_PER_SEC;
    LINFO("%g ms/frame", (s_elapsed * 1000) / frames);
    LINFO("%g frames/sec", frames / s_elapsed);

    return true;
}

void DestroyApp(void) {
    ShutdownWindow(&s_state.win_state);
    s_is_init = false;
}
