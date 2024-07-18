#include "input.h"

#include <SDL.h>

#include "../types.h"
#include "logging.h"

static const u8* KeyState = NULL;
static b8        IsInit   = false;

b8               InitSystemInput(void) {
    if (IsInit) {
        LERROR("Double initialization of input system.");
        return false;
    }

    KeyState = SDL_GetKeyboardState(NULL);
    if (!KeyState) { return false; }
    return true;
}

b8 KeyDown(KeyCode _kc) { return KeyState[_kc]; }
