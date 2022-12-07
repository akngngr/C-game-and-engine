//Created OpenGL context, opening a window and handling quit event

#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "engine/global.h"

 //inside the main function Supplying SDL parameters for OpenGL
int main(int argc, char *argv[]) {
    render_init();

    bool should_quit = false;

    //while false continue looping
    while(!should_quit) {
        //get events from SDL
        SDL_Event event;

        //if you get the quit event type then exit the loop
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                should_quit = true;
                break;
            default:
                break;
            }
        }

        render_begin();

        render_quad(
            (vec2){global.render.width * 0.5, global.render.height * 0.5},
            (vec2){50, 50},
            (vec4){0, 1, 0, 1});

            render_end();
    }

    return 0;
}
