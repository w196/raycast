#ifndef utils_h
#define utils_h

#include <stdio.h>
#include <stdint.h>

#include "level.c"

typedef struct colour_s {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} colour_t;

colour_t tile_colour(tile_t);

// Point for handling positions
typedef struct point_s {
    double x;
    double y;
} point_t;

// Line that will be output to the frame buffer, radiating from centre.
typedef struct line_s {
    colour_t colour;
    unsigned int length;
} line_t;

// Vector to handle angles and directions
typedef double* vec2_t; // [x, y]
vec2_t vec2_from_angle(double);
void print_vector(vec2_t); // debug
vec2_t vec2_reciprocal(vec2_t);
vec2_t vec2_negative(vec2_t);
void vec2_add_to_point(vec2_t, point_t*, int /*speed*/);

#endif /* utils_h */
