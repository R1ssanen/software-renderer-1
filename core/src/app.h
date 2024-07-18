#ifndef APP_H
#define APP_H

#include "api.h"
#include "types.h"
#include "window.h"

b8 APIENTRY   CreateApp(const WindowConfig* WinConf);

b8 APIENTRY   RunApp(void);

void APIENTRY DestroyApp(void);

#endif
