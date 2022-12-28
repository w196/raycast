#define SCRW 800
#define SCRH 600

#define FLEN 0.75 // focal length. lower = higher fov

#define CAST_PRECISION 100

#define SHADOW_DEPTH 30

#ifndef render_h
#define render_h

#include <stdio.h>
#include <SDL.h>
#include <math.h>
#include <stdbool.h>

#include "level.c"
#include "utils.h"

void r_drawlines(SDL_Renderer*, line_t[], unsigned int /*width*/, unsigned int /*height*/);

line_t r_cast(point_t /*origin*/, double /*angle*/, double /*offset*/);


#endif /* renderer_h */
