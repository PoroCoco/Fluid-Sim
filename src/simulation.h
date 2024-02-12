#pragma once

typedef struct sim {
    // Staggered grid
    int cells_x; // Number of cells on the x axis 
    int cells_y; 
    int glines_x; //  Number of grid lines on the x axis (cells_x + 1)
    int glines_y;

    double *u; // x-direction velocities
    double *v; // y-direction velocities
} sim;


sim * sim_init(int width, int height);

void sim_step(sim * s, double timestep);

void sim_destroy(sim * s);
