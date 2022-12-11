#pragma once

#include "render/render.h"
#include "config.h"
#include "input.h"
#include "time.h"

//global struct is an extern variable meaning it's declared but has no memory assigned with it yet. Once this is used elsewhere this symbol will be associated with that memory so this header file can be included and access the variable anywhere.
typedef struct global {
    Render_State render;
    Config_State config;
    Input_State input;
    Time_State time;
} Global;

extern Global global;

