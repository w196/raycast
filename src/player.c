#include "player.h"

player_t p_init(double x, double y, double angle) {
    if (angle > 360)
        perror("player_init(): invalid angle");
    player_t buffer;
    
    buffer.pos.x = x;
    buffer.pos.y = y;
    buffer.angle = angle;
    
    return buffer;
}

line_t* p_cast(player_t player, line_t** framebuffer) {
    
    for (int i = 0; i < SCRW; i++) {
        double i_rel_centre = (i)-(SCRW/2); // position of i relative to centre of screen
        double relative_angle = atan(i_rel_centre / (FLEN * SCRW));
        (*framebuffer)[i] = r_cast(player.pos, player.angle+(relative_angle * (180/M_PI)), relative_angle);
    }
}

void p_move(player_t* player, move_t move) {
    switch (move) {
        case MOVE_F:
            vec2_add_to_point(vec2_from_angle(player->angle), &player->pos, WSPD);
            break;
        case MOVE_B:
            vec2_add_to_point(vec2_negative(vec2_from_angle(player->angle)), &player->pos, WSPD);
            break;
        case MOVE_R:
            vec2_add_to_point(vec2_from_angle(player->angle+90), &player->pos, WSPD);
            break;
        case MOVE_L:
            vec2_add_to_point(vec2_from_angle(player->angle+270), &player->pos, WSPD);
            break;
        case ROTATE_L:
            player->angle -= LSPD;
            break;
        case ROTATE_R:
            player->angle += LSPD;
            break;
    }
}
