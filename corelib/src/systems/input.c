#include "input.h"

#include <SDL.h>

#include "../types.h"
#include "logging.h"

static const u8* s_kb_state = NULL;
static b8        s_is_init  = false;

b8               InitSystemInput(void) {
    if (s_is_init) {
        LERROR("Double initialization of input system.");
        return false;
    }

    s_kb_state = SDL_GetKeyboardState(NULL);
    if (!s_kb_state) { return false; }
    return true;
}

b8   KeyDown(KeyCode _kc) { return s_kb_state[_kc]; }

void PumpEvents(void) { SDL_PumpEvents(); }
