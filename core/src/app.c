#include "app.h"

#include "systems/input.h"
#include "systems/logging.h"
#include "types.h"
#include "window.h"

typedef struct AppState {
    WindowState WinState;
    b8          Running;
    b8          NoFocus;
} AppState;

static AppState State;
static b8       IsInit = false;

b8              CreateApp(const WindowConfig* Conf) {
    if (IsInit) {
        LERROR("Double initialization of application.");
        return false;
    }

    if (!InitSystemInput()) {
        LERROR("Could not initialize input system.");
        return false;
    }

    if (!SetupWindow(&State.WinState, Conf)) { return false; }
    State.Running = true;
    State.NoFocus = false;
    IsInit        = true;

    return true;
}

#include <SDL.h>

b8 APIENTRY RunApp(void) {

    while (State.Running) {
        SDL_PumpEvents();
        if (KeyDown(KC_Q)) { State.Running = false; }
    }

    ShutdownWindow(&State.WinState);
    return true;
}

void DestroyApp(void) { IsInit = false; }
