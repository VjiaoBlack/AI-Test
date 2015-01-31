#include "test.h"




int main(int argv, char* argc[]) {
    init();
    mspf = 1000 / FPS;

    mouse_x = mouse_y = 0;
    mouse_xvel = mouse_yvel = 0;
    int delay;
    dmg = 0;

    enemy_x = enemy_y = 100;
    player_x = player_y = 100;


    open_window(800,640);
    SDL_WM_GrabInput(SDL_GRAB_ON);
    SDL_ShowCursor(1);

    struct timeval pre, post;




    while (1) {

        gettimeofday(&pre, NULL);

        get_input();
        if (keys_held[SDLK_q]) {
            close_window();
            quit(0);
        }

        enemy_ai();
        if (dmg >= 100) {
            close_window();
            quit(0);
        }



        int dx = player_x - mouse_x;
        int dy = player_y - mouse_y;

        float angle = atan2(dy, dx);

        if (abs(player_x - mouse_x) < 3 && abs(player_y - mouse_y) < 3) {
            player_x = mouse_x;
            player_y = mouse_y;
            dmg++;
        } else {
            if (player_x != mouse_x)
                player_x -= 4.0 * cos(angle);

            if (player_y != mouse_y)
                player_y -= 4.0 * sin(angle);
        }


        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        draw();
        SDL_Flip(screen);



        gettimeofday(&post, NULL);


        if ( (delay = (post.tv_usec - pre.tv_usec) / 1000 + (post.tv_sec - pre.tv_sec)* 1000) < mspf) {
            SDL_Delay(mspf - delay);
        }
    }


    // this code should never run.

    close_window();
    quit(0);
    return 0; // quiets warnings. quit() exits already.
}


// gets input from the keyboard
void get_input() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            close_window();
            quit(0);
        }
        if (event.type == SDL_KEYUP) {  // any key is released
            keys_held[event.key.keysym.sym] = 0;
        }
        if (event.type == SDL_KEYDOWN) {  // any key is pressed
            keys_held[event.key.keysym.sym] = 1;
        }
        if (event.type == SDL_MOUSEMOTION) {
            mouse_x = event.motion.x;
            mouse_y = event.motion.y;


            mouse_xvel = event.motion.xrel;
            mouse_yvel = event.motion.yrel;
        }
    }
}


void draw() {

    draw_circle(screen,player_x, player_y,5,pixel(100,200 - dmg,100));

    draw_circle(screen,enemy_x, enemy_y, 10, pixel(100 + dmg,100,100));

}

void enemy_ai() {
    int dx = enemy_x - player_x;
    int dy = enemy_y - player_y;

    float angle = atan2(dy, dx);

    if (abs(enemy_x - player_x) < 3 && abs(enemy_y - player_y) < 3) {
        enemy_x = player_x;
        enemy_y = player_y;
        dmg++;
    } else {
        if (enemy_x != player_x)
            enemy_x -= 3.0 * cos(angle);

        if (enemy_y != player_y)
            enemy_y -= 3.0 * sin(angle);
    }
}
