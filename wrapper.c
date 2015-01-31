#include "wrapper.h"

Uint32 pixel(int r, int g, int b) {
    return SDL_MapRGB(screen->format, r, g, b);
}

Uint32 get_pixel(SDL_Surface *surface, int x, int y) {
    int bpp = 4;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    return (Uint32) *p;
}

void put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel) {
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) {
        return;
    }

    int bpp = 4;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    *(Uint32 *)p = pixel;
    return;
}

void init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    return;
}

void open_window(int width, int height) {
    screen = SDL_SetVideoMode(width, height, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL) {
        printf("Couldn't set screen mode %d x %d: %s\n", width, height, SDL_GetError());
        quit(1);
    }
    return;
}

void close_window() {
    SDL_FreeSurface(screen); // how to check if screen is initialized
    exit(0);
    return;
}

void quit(int code) {
    SDL_Quit();
    exit(1);
    return;
}
