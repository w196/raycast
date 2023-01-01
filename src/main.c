#include <SDL.h>

#include "window.h"
#include "render.h"
#include "player.h"

int main(int argc, const char * argv[]) {
    master_window_t master = master_init("raycast", SCRW, SCRH);
    player_t player = p_init(1.5, 2.5, 90.0);

    SDL_Rect ceiling = { .x = 0, .y = 0,      .w = SCRW, .h = SCRH/2 };
    SDL_Rect floor   = { .x = 0, .y = SCRH/2, .w = SCRW, .h = SCRH/2 };
    
    line_t* frame_buffer = malloc(sizeof(line_t)*SCRW);

    p_cast(player, &frame_buffer);

    // game loop
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                        case SDLK_f:
                            break;
                        case SDLK_w:
                            p_move(&player, MOVE_F);
                            break;
                        case SDLK_s:
                            p_move(&player, MOVE_B);
                            break;
                        case SDLK_a:
                            p_move(&player, MOVE_L);
                            break;
                        case SDLK_d:
                            p_move(&player, MOVE_R);
                            break;
                        case SDLK_q:
                            p_move(&player, ROTATE_L);
                            break;
                        case SDLK_e:
                            p_move(&player, ROTATE_R);
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
/*
        SDL_SetRenderDrawColor(master.renderer, 0, 0, 0, 255);
        SDL_RenderClear(master.renderer);
*/
        SDL_SetRenderDrawColor(master.renderer, 116, 176, 122, 255);
        SDL_RenderDrawRect(master.renderer, &floor);
        SDL_RenderFillRect(master.renderer, &floor);

        SDL_SetRenderDrawColor(master.renderer, 125, 218, 232, 255);
        SDL_RenderDrawRect(master.renderer, &ceiling);
        SDL_RenderFillRect(master.renderer, &ceiling);

        p_cast(player, &frame_buffer);
        r_drawlines(master.renderer, frame_buffer, SCRW, SCRH);

        SDL_RenderPresent(master.renderer);
    }
    
    master_cleanup(&master);
    
    return 0;
}
