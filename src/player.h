#define WSPD 10 // lower is faster
#define LSPD 2 // degree per event

#ifndef player_h
#define player_h

#include <stdio.h>

#include "render.h"

typedef enum moves {
    MOVE_F,
    MOVE_B,
    MOVE_L,
    MOVE_R,
    ROTATE_L,
    ROTATE_R
} move_t;

typedef struct player_s {
    point_t pos;
    double angle;
} player_t;

player_t p_init(double, double, double);
void p_move(player_t*, move_t);
void p_rotate(player_t*, double);
line_t* p_cast(player_t);

#endif /* player_h */
