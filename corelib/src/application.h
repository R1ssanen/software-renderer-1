#ifndef APP_H
#define APP_H

#include "api.h"
#include "types.h"
#include "window.h"

b8 APIENTRY   CreateApp(const WindowConfig* win_conf);

b8 APIENTRY   RunApp(void);

void APIENTRY DestroyApp(void);

#endif
