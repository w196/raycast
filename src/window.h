#ifndef window_h
#define window_h

#include <SDL.h>
#include <stdio.h>

typedef struct master_window_s {
    SDL_Window* window;
    SDL_Renderer* renderer;
} master_window_t;

master_window_t master_init(char* /*title*/, int /*h*/, int /*w*/);
void master_clear(master_window_t*);
void master_cleanup(master_window_t*);

#endif /* window_h */
