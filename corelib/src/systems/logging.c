#include "logging.h"

#include <stdarg.h>
#include <stdio.h>

#if defined(LOG_NO_COLOR)
#define AS_WHITE(_msg)    _msg
#define AS_GREEN(_msg)    _msg
#define AS_CYAN(_msg)     _msg
#define AS_YELLOW(_msg)   _msg
#define AS_RED(_msg)      _msg
#define AS_BOLD_RED(_msg) _msg
#else
#define AS_WHITE(_msg)    "\e[1;37m" _Msg "\e[1;0m"
#define AS_CYAN(_msg)     "\e[1;36m" _Msg "\e[1;0m"
#define AS_GREEN(_msg)    "\e[1;32m" _Msg "\e[1;0m"
#define AS_YELLOW(_msg)   "\e[1;33m" _Msg "\e[1;0m"
#define AS_RED(_msg)      "\e[1;31m" _Msg "\e[1;0m"
#define AS_BOLD_RED(_msg) "\e[1;41m" _Msg "\e[1;0m"
#endif

void _LogMsg(LogLevel _type, const char* _fmt, ...) {
    char    log_msg[1024];
    va_list vargs;
    va_start(vargs, _fmt);
    vsprintf(log_msg, _fmt, vargs);
    va_end(vargs);

    switch (_type) {
    case LOG_TRACE: fprintf(stdout, "%s %s\n", AS_WHITE("[trace]"), log_msg); return;
    case LOG_DEBUG: fprintf(stdout, "%s %s\n", AS_CYAN("[debug]"), log_msg); return;
    case LOG_INFO: fprintf(stdout, "%s %s\n", AS_GREEN("[info]"), log_msg); return;
    case LOG_WARN: fprintf(stderr, "%s %s\n", AS_YELLOW("[warning]"), log_msg); return;
    case LOG_ERROR: fprintf(stderr, "%s %s\n", AS_RED("[error]"), log_msg); return;
    case LOG_FATAL: fprintf(stderr, "%s %s\n", AS_BOLD_RED("[fatal]"), log_msg); return;

    default: return;
    }
}
