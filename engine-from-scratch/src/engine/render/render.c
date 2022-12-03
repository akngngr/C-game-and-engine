#include <glad/glad.h>

#include "../global.h"
#include "render.h"
#include "render_internal.h"

//defined a state variable that will hold any internal state that we need to share inside the render module
static Render_State_Internal state = {0};

void render_init(void) {
    global.render.width = 800;
    global.render.height = 600;
    global.render.window = render_init_window(global.render.width, global.render.height);
    //three arguments are all pointers to unsigned 32-bit integers
    render_init_quad(&state.vao_quad, &state.vbo_quad, &state.ebo_quad);
}

void render_begin(void) {
    //BG color of the window before anything is drawn
    glClearColor(0.08, 0.1, 0.1, 1);
    //clear color bufer
    glClear(GL_COLOR_BUFFER_BIT);
}

void render_end(void) {
    SDL_GL_SwapWindow(global.render.window);
}

void render_quad(vec2 pos, vec2 size, vec4 color) {
    glBindVertexArray(state.vao_quad);

    //called glPolygonMode function and set to draw GL lines
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //draw something made of trangles that has 6 elements.
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    //unbine vao
    glBindVertexArray(0);

}


void render_init(void);
void render_begin(void);
void render_end(void);
void render_quad(vec2 pos, vec2 size, vec4 color);