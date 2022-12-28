#include "window.h"

master_window_t master_init(char* title, int w, int h) {
    master_window_t _w;
    
    // init all pointers to NULL
    _w.window = NULL;
    _w.renderer = NULL;
    
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialise SDL! %s\n", SDL_GetError());
        exit(1);
    }

    // choose driver, otherwise it breaks on macOS
    if (SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl") == SDL_FALSE)
        printf("Failed to set render driver hint!\n");
    
    // create window
    _w.window = SDL_CreateWindow(
                                title,
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                w, h,
                                SDL_WINDOW_SHOWN);
    
    if (_w.window == NULL) {
        printf("Could not create window! %s\n", SDL_GetError());
        exit(1);
    }

    // create renderer
    _w.renderer = SDL_CreateRenderer(_w.window, -1, SDL_RENDERER_ACCELERATED);
    if (_w.renderer == NULL) {
        printf("Could not create renderer! %s\n", SDL_GetError());
        exit(1);
    }
    return _w;
}

void master_clear(master_window_t* w) {
    SDL_SetRenderDrawColor(w->renderer, 0, 30, 200, 255);
    SDL_RenderClear(w->renderer);
    SDL_RenderPresent(w->renderer);
}

void master_draw_line(master_window_t* w) {
    SDL_SetRenderDrawColor(w->renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(w->renderer, 200, 200, 300, 300);
    SDL_RenderPresent(w->renderer);
}

void master_cleanup(master_window_t* w) {
    SDL_DestroyWindow(w->window);
    SDL_Quit();
}

