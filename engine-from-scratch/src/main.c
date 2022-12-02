//Created OpenGL context, opening a window and handling quit event

#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

 //inside the main function Supplying SDL parameters for OpenGL
int main(int argc, char *argv[]) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); 
    //Profile type is Core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    //Set major and minor versions

    //initialize SDL if we don't get expected parameters then print error and exit program
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not init SDL: %s\n", SDL_GetError());
        exit(1);
    }

    //pointer to an SDL window
    SDL_Window *window = SDL_CreateWindow(
        "MyGame",//window title
        SDL_WINDOWPOS_CENTERED, //macro provided by SDL to center the window
        SDL_WINDOWPOS_CENTERED,
        800,//width
        600,//height
        SDL_WINDOW_OPENGL //flags the window has. Use OpenGL
    );

    //if fails print error and exit
    if(!window) {
        printf("Failed to init window %s\n", SDL_GetError());
        exit(1);
    }

    //create OpenGL Context
    SDL_GL_CreateContext(window);
    //glad loads all the pointers into the right places in the memory
    //if fails print error and exit
    if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        printf("Failed to load GL: %s\n", SDL_GetError());
        exit(1);
    }

    //when successful, print out below info to the terminal
    puts("OpenGL Loaded");
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

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
    }

    puts("Hello there!");
    return 0;
}
