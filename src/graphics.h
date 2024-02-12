#pragma once
#include <SDL2/SDL.h>
#include "simulation.h"

typedef struct graphics{
    int height;
    int width;

    SDL_Window* window;
    SDL_Renderer* renderer;
} graphics;

graphics * graphics_init(int width, int height);

void graphics_render(graphics *g, sim * s, int cell_resolution);

void graphics_destroy(graphics *g);