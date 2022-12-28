#include "utils.h"
#include <math.h>
#include <stdlib.h>

// do not attempt to create vector any way other than this func
vec2_t vec2_from_angle(double angle) {
    vec2_t vec = (vec2_t) malloc(sizeof(int) * 2);
    double rad = angle * (M_PI / 180);
    vec[0] = sin(rad);
    vec[1] = cos(rad);
    return vec;
}

vec2_t vec2_reciprocal(vec2_t vec) {
    vec2_t buf = vec; // copy
    buf[0] = vec[1];
    buf[1] = vec[0];
    return buf;
}

vec2_t vec2_negative(vec2_t vec) {
    vec2_t buf = vec; // copy
    buf[0] = -vec[0];
    buf[1] = -vec[1];
    return buf;
}

void vec2_add_to_point(vec2_t vec, point_t* point, int speed) {
    point->x += vec[0]/speed;
    point->y += vec[1]/speed;
}

void print_vector(vec2_t vec) {
    printf("[%f %f]\n", vec[0], vec[1]);
}
