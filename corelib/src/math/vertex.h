#ifndef VERTEX_H
#define VERTEX_H

#include "vecm/vec/vec2.h"
#include "vecm/vec/vec3f.h"

typedef struct Vertex {
    mvec3f pos;
    mvec3f color;
    mvec2f uv;
} Vertex;

#endif
