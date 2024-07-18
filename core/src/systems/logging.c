#include "logging.h"

#include <stdarg.h>
#include <stdio.h>

#if defined(LOG_NO_COLOR)
#define AS_WHITE(_Msg)    _Msg
#define AS_GREEN(_Msg)    _Msg
#define AS_CYAN(_Msg)     _Msg
#define AS_YELLOW(_Msg)   _Msg
#define AS_RED(_Msg)      _Msg
#define AS_BOLD_RED(_Msg) _Msg
#else
#define AS_WHITE(_Msg)    "\e[1;37m" _Msg "\e[1;0m"
#define AS_CYAN(_Msg)     "\e[1;36m" _Msg "\e[1;0m"
#define AS_GREEN(_Msg)    "\e[1;32m" _Msg "\e[1;0m"
#define AS_YELLOW(_Msg)   "\e[1;33m" _Msg "\e[1;0m"
#define AS_RED(_Msg)      "\e[1;31m" _Msg "\e[1;0m"
#define AS_BOLD_RED(_Msg) "\e[1;41m" _Msg "\e[1;0m"
#endif

void _LogMsg(LogLevel _Type, const char* _Fmt, ...) {
    char    LogMsg[1024];
    va_list Args;
    va_start(Args, _Fmt);
    vsprintf(LogMsg, _Fmt, Args);
    va_end(Args);

    switch (_Type) {
    case LOG_TRACE: fprintf(stdout, "%s %s\n", AS_WHITE("[trace]"), LogMsg); return;
    case LOG_DEBUG: fprintf(stdout, "%s %s\n", AS_CYAN("[debug]"), LogMsg); return;
    case LOG_INFO: fprintf(stdout, "%s %s\n", AS_GREEN("[info]"), LogMsg); return;
    case LOG_WARN: fprintf(stderr, "%s %s\n", AS_YELLOW("[warning]"), LogMsg); return;
    case LOG_ERROR: fprintf(stderr, "%s %s\n", AS_RED("[error]"), LogMsg); return;
    case LOG_FATAL: fprintf(stderr, "%s %s\n", AS_BOLD_RED("[fatal]"), LogMsg); return;

    default: return;
    }
}
