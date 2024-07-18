#ifndef INPUT_H
#define INPUT_H

#include "../api.h"
#include "../types.h"

typedef enum KeyCode { KC_INVALID = 0, KC_Q = 20 } KeyCode;

b8          InitSystemInput(void);

b8 APIENTRY KeyDown(KeyCode _kc);

#endif
