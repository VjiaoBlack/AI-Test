#include <stdio.h>
#include <sys/time.h>
#include "graphics.h"
#include "math.h"

#define FPS 60

int xo, yo;
float mspf;

// the keys on the keyboard go from 0 to 322 in SDL.
char keys_held[323] = {0}; // assignment usually done during setup, but
                           // the = {0} syntax only works now.

int mouse_x, mouse_y;
int mouse_xvel, mouse_yvel;

int player_x, player_y;


int dmg;



int enemy_x, enemy_y;

void draw();
void get_input();
void enemy_ai();
