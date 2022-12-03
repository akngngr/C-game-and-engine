//if TYPES_H is not yet defined then include everything until the #endif directive
//then immediately define an empty constant TYPES_H
//after the first the header types.h is included it won't be included again.'
#ifndef TYPES_H
#define TYPES_H

#include <inttypes.h>

//typedef tells compiler to look for the left type when it sees your define type on the right.
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;
typedef double f64;

#endif