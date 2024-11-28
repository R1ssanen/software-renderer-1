#ifndef _RENDER_H_
#define _RENDER_H_

#include <vecm/vec/vec3f.h>

#include "api.h"
#include "ebo.h"
#include "target.h"

void RenderTriangle(RenderTarget* tg, u32 (*shade)(u64, f32*), mvec3f* a, mvec3f* b, mvec3f* c);

void RHAPI DrawElementsTriangle(RenderTarget* tg, const ElementBuffer* _ebo);

#endif
