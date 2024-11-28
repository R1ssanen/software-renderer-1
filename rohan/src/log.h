#ifndef _LOG_H_
#define _LOG_H_

#include "api.h"

typedef enum LogLevel {
    LOG_TRACE = 0,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_FATAL
} LogLevel;

void RHAPI _LogMsg(LogLevel _type, const char* _fmt, ...);

#define LTRACE(_Fmt, ...) _LogMsg(LOG_TRACE, _Fmt, ##__VA_ARGS__)
#define LDEBUG(_Fmt, ...) _LogMsg(LOG_DEBUG, _Fmt, ##__VA_ARGS__)
#define LINFO(_Fmt, ...)  _LogMsg(LOG_INFO, _Fmt, ##__VA_ARGS__)
#define LWARN(_Fmt, ...)  _LogMsg(LOG_WARN, _Fmt, ##__VA_ARGS__)
#define LERROR(_Fmt, ...) _LogMsg(LOG_ERROR, _Fmt, ##__VA_ARGS__)
#define LFATAL(_Fmt, ...) _LogMsg(LOG_FATAL, _Fmt, ##__VA_ARGS__)

#endif
