#include <glad/glad.h>
#include <SDL2/SDL.h>

#include "../util.h"
#include "../global.h"

#include "render.h"
#include "render_internal.h"

SDL_Window *render_init_window(u32 width, u32 height) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); 
    //Profile type is Core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    //Set major and minor versions

    //initialize SDL if we don't get expected parameters then print error and exit program
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        ERROR_EXIT("Could not init SDL: %s\n", SDL_GetError());

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
        ERROR_EXIT("Failed to init window %s\n", SDL_GetError());
    }

    //create OpenGL Context
    SDL_GL_CreateContext(window);
    //glad loads all the pointers into the right places in the memory
    //if fails print error and exit
    if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        ERROR_EXIT("Failed to load GL: %s\n", SDL_GetError());
    }

    //when successful, print out below info to the terminal
    puts("OpenGL Loaded");
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

    return window;
}

void render_init_quad(u32 *vao, u32 *vbo, u32 *ebo) {
    // x, y, z, u, v
    f32 vertices[] = {
        0.5, 0.5, 0, 0, 0,
        0.5, -0.5, 0, 0, 1,
        -0.5, -0.5, 0, 1, 1,
        -0.5, 0.5, 0, 1, 0
    };

    u32 indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    glGenVertexArrays(1, vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(*vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //xyz
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), NULL);
    glEnableVertexAttribArray(0);

    //uv
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)(3 * sizeof(f32)));
    glEnableVertexAttribArray(1);
}
