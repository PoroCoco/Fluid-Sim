#include <SDL2/SDL.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#define _POSIX_C_SOURCE 199309L
#include <time.h>

#include "graphics.h"
#include "simulation.h"

int main(int argc, char** argv)
{
    int width = 1920;
    int height = 1080;
    int cell_resolution = 20;
    graphics *g = graphics_init(width, height);
    sim *s = sim_init(width/cell_resolution, height/cell_resolution);


    bool running = true;
    size_t frame_count = 0;
    struct timespec start, end;

    while(running){
        clock_gettime(CLOCK_MONOTONIC_RAW, &start);
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)){
                running = false;                
                graphics_destroy(g);
            }
        }
        sim_step(s, (double) 1/10.0);
        graphics_render(g, s, cell_resolution);
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);
        uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
        printf("Frame %zu : time %.3lf\n", frame_count, delta_us/1000.0);
        frame_count++;
    }


    return 0;
}