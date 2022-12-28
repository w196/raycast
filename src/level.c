#define MAPSX 10
#define MAPSY 10

#ifndef level_c
#define level_c

typedef enum tile_e {
    NIL,
    RED,
    YEL,
    GRN,
    BLU
} tile_t;

typedef enum face_e {
    FACE_N,
    FACE_S,
    FACE_W,
    FACE_E
} face_t;

static tile_t level[MAPSX][MAPSY] = { // TODO make it create these automagically.
    {RED, YEL, RED, YEL, RED, YEL, RED, YEL, RED, RED},
    {RED, NIL, NIL, NIL, NIL, NIL, GRN, NIL, NIL, YEL},
    {YEL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, RED},
    {RED, NIL, NIL, NIL, NIL, NIL, GRN, NIL, NIL, YEL},
    {YEL, NIL, NIL, BLU, NIL, NIL, NIL, NIL, NIL, RED},
    {RED, NIL, NIL, GRN, NIL, NIL, NIL, NIL, NIL, YEL},
    {YEL, NIL, NIL, BLU, NIL, NIL, NIL, NIL, NIL, RED},
    {RED, NIL, NIL, GRN, NIL, NIL, NIL, NIL, NIL, YEL},
    {YEL, NIL, NIL, BLU, NIL, NIL, NIL, NIL, NIL, RED},
    {RED, RED, YEL, RED, YEL, RED, YEL, RED, RED, YEL}
};

#endif
