#ifndef _EBO_H_
#define _EBO_H_

#include "types.h"

typedef struct {
    void* prims;
    u64   prim_count;
    u64   prim_size;
    u64   prims_per_elem;
    u64*  ids;
    u64   id_count;
} ElementBuffer;

static inline ElementBuffer CreateElementBuffer(
    void* primitives, u64 prim_count, u64 prim_size, u64 primitives_per_element, u64* indices,
    u64 id_count
) {
    return (ElementBuffer){ .prims          = primitives,
                            .prim_count     = prim_count,
                            .prim_size      = prim_size,
                            .prims_per_elem = primitives_per_element,
                            .ids            = indices,
                            .id_count       = id_count };
}

#endif
