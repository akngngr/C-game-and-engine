#ifndef GLOBAL_H
#define GLOBAL_H

#include "render/render.h"

//global struct is an extern variable meaning it's declared but has no memory assigned with it yet. Once this is used elsewhere this symbol will be associated with that memory so this header file can be included and access the variable anywhere.
typedef struct global {
    Render_State render;
} Global;

extern Global global;

#endif