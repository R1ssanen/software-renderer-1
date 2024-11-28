#ifndef _API_H_
#define _API_H_

#if defined(__linux__)
#    define RHAPI __attribute__((visibility("default")))

#else
#    error "OS not supported."
#endif
#endif
