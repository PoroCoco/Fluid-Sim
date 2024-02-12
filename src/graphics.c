#include "graphics.h"
#include <stdio.h>
#include <assert.h>

graphics * graphics_init(int width, int height){
    graphics *g = malloc(sizeof(*g));
    assert(g != NULL);
 
    g->width = width;
    g->height = height;

    if (SDL_Init(SDL_INIT_VIDEO) != 0 ){
        fprintf(stdout,"SDL Init failed : (%s)\n", SDL_GetError());
        return NULL;
    }

    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Fluid Sim",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window){
        fprintf(stderr,"SDL window creation failed : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    g->window = window;

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer){
        fprintf(stderr,"SDL renderer creation failed : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    g->renderer = renderer;
    
    return g;
}


void graphics_render_cells(graphics *g, sim * s, int cell_resolution){
    for (int y = 0; y < s->cells_y; y++){
        for (int x = 0; x < s->cells_x; x++){
            SDL_Rect rect = {.h = cell_resolution, .w = cell_resolution, .x = cell_resolution*x, .y = cell_resolution*y};
            SDL_SetRenderDrawColor(g->renderer, rand()%255, rand()%255, rand()%255, 255);
            SDL_RenderFillRect(g->renderer, &rect);
        }
    }
}

void graphics_render_grid(graphics *g, sim * s, int cell_resolution){
    SDL_SetRenderDrawColor(g->renderer, 128, 128, 128, 255);
    for (int x = 0; x < s->glines_x; x++){
        SDL_RenderDrawLine(g->renderer, cell_resolution*x, 0, cell_resolution*x, g->height); 
    }
    for (int y = 0; y < s->glines_y; y++){
        SDL_RenderDrawLine(g->renderer, 0, cell_resolution*y, g->width, cell_resolution*y); 
    }
}

void graphics_render(graphics *g, sim * s, int cell_resolution){
    // render cells
    graphics_render_cells(g, s, cell_resolution);
    // render grid
    graphics_render_grid(g, s, cell_resolution);

    SDL_RenderPresent(g->renderer);
}


void graphics_destroy(graphics *g){
    SDL_DestroyRenderer(g->renderer); 
    SDL_DestroyWindow(g->window);
    free(g);
    SDL_Quit();
}