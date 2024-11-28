#include "../../rohan/src/shader.h"

FRAGMENT_MODULE(1.0)

u32 fmain() {
    return ((u8)(0xff * BARYCOORD[0]) << 16) + ((u8)(0xff * BARYCOORD[1]) << 8) +
           (u8)(0xff * BARYCOORD[2]);
}
