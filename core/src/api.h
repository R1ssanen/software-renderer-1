#ifndef API_H
#define API_H

#if defined(__linux__)
#define APIENTRY __attribute__((visibility("default")))

#else
#error "OS not supported."
#endif
#endif
