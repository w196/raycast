#include "render.h"

colour_t tile_colour(tile_t tile) {
    colour_t buf;
    switch (tile) {
        case YEL:
            buf.r = 207;
            buf.g = 194;
            buf.b = 23;
            break;
        case RED:
            buf.r = 207;
            buf.g = 23;
            buf.b = 23;
            break;
        case GRN:
            buf.r = 95;
            buf.g = 181;
            buf.b = 42;
            break;
        case BLU:
            buf.r = 42;
            buf.g = 114;
            buf.b = 181;
            break;
        default:
            buf.r = 255;
            buf.g = 255;
            buf.b = 255;
            printf("Error: Requested colour of empty tile\n");
            break;
    }
    return buf;
}

void colour_brightness(colour_t* clr, int factor) { // just to make tile_shade() look less clunky
    // prevent underflows. clumsy but works
    if (factor < 0 && clr->r < abs(factor)) clr->r = 0;
    else clr->r += factor;
    
    if (factor < 0 && clr->g < abs(factor)) clr->g = 0;
    else clr->g += factor;
    
    if (factor < 0 && clr->b < abs(factor)) clr->b = 0;
    else clr->b += factor;
}

face_t r_face(point_t coords) {
    face_t face;
    
    // relative position of ray in tile (0,0 = NW corner)
    double rx = coords.x - floor(coords.x);
    double ry = coords.y - floor(coords.y);
    
    // determine which face is closest
    // this may be inefficient
    if (rx <= (-ry) + 1) {
        if (rx > ry) face = FACE_W;
        else face = FACE_N;
    } else {
        if (rx > ry) face = FACE_S;
        else face = FACE_E;
    }
    
    return face;
}

colour_t r_shade(colour_t source, point_t coords) {
    face_t hit = r_face(coords);
    colour_t buffer = source;
   
    switch (hit) {
        case FACE_W:
            colour_brightness(&buffer, -(SHADOW_DEPTH/2));
            break;
        case FACE_N:
            break;
        case FACE_E:
            colour_brightness(&buffer, -(SHADOW_DEPTH/2));
            break;
        case FACE_S:
            colour_brightness(&buffer, -SHADOW_DEPTH);
            break;
    }
    
    return buffer;
}

void r_drawlines(SDL_Renderer* renderer, line_t lines[], unsigned int w, unsigned int h) {
    unsigned int centre = h / 2;
    
    // draw lines radiating from center
    for (int i = 0; i < w; i++) {
        SDL_SetRenderDrawColor(renderer, lines[i].colour.r, lines[i].colour.g, lines[i].colour.b, 255);
        int offset = lines[i].length/2;
        SDL_RenderDrawLine(renderer, i, centre-offset, i, centre+offset);
    }
    SDL_RenderPresent(renderer);
}

line_t r_cast(point_t origin, double angle, double rel_angle) {
    // this is pretty inefficient but it's easy to understand
    line_t buffer;
    
    point_t current = origin; // copy
    vec2_t direction = vec2_from_angle(angle);
    
    double length = 0.0;
    double len_adj = 0.0; // adjusted for fisheye effect
    
    bool casting = true;
    while (casting) {
        int fx = floor(current.x);
        int fy = floor(current.y);
        if (level[fx][fy] != NIL) {
            colour_t raw_colour = tile_colour(level[fx][fy]);
            buffer.colour = r_shade(raw_colour, current);
            
            casting = false;
        }
        
        current.x += direction[0] / CAST_PRECISION;
        current.y += direction[1] / CAST_PRECISION;
        length = sqrt(pow(origin.x-current.x, 2) + pow(origin.y-current.y, 2));
        len_adj = length * cos(rel_angle);

    }
    buffer.length = SCRH / len_adj+1; // eliminate divison by 0
    return buffer;
}

