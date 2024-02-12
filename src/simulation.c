#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "simulation.h"

sim * sim_init(int width, int height){
    sim * s = malloc(sizeof(*s));
    assert(s);

    s->cells_x = width;
    s->glines_x = width + 1;
    s->cells_y = height;
    s->glines_y = height + 1;

    s->u = malloc(sizeof(*(s->u)) * s->glines_x);
    assert(s->u);
    s->v = malloc(sizeof(*(s->v)) * s->glines_y);
    assert(s->v);

    return s; 
}

void sim_step(sim * s, double timestep){
    //sim_apply_forces();
    //sim_projection();
    //sim_advection();
}



void sim_destroy(sim * s){
    free(s->u);
    free(s->v);
    free(s);
}