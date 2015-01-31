#include "wrapper.h"


void bresenham(int*, int*, int*, int*, int, int);
void draw_rect(SDL_Surface*, int, int, int, int, Uint32);
void fill_rect(SDL_Surface*, int, int, int, int, Uint32);

void draw_line(SDL_Surface*, int, int, int, int, Uint32);

void draw_triangle(SDL_Surface*, int, int, int, int, int, int, Uint32);
void fill_triangle(SDL_Surface*, int, int, int, int, int, int, Uint32);

void swap(int*,int*);

void draw_circle(SDL_Surface*, int, int, int, Uint32);

