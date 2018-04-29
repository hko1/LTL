//SDL2 flashing random color example
//Should work on iOS/Android/Mac/Windows/Linux

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

#include <stdlib.h> //rand()
#include <string> //rand()
#include "Ship.h"
#include "Image.h"


static bool quitting = false;
static SDL_Window *window = NULL;
static SDL_GLContext gl_context;
static int WINDOW_WIDTH = 1280;
static int WINDOW_HEIGHT = 720;
static Image *background = NULL;
static Ship *ship = NULL;

void orthogonalProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, 0.0f, 1.0f);
}

void render() {
    SDL_GL_MakeCurrent(window, gl_context);
    // clear the window to black
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT );
    // activate orthogonal projection.
    // this is good with sprites.
    orthogonalProjection();
    // draw the background in the center of the window
    glBlendFunc(GL_ONE, GL_ZERO);
    background->draw(
        WINDOW_WIDTH*0.5f,
        WINDOW_HEIGHT*0.5f);
    // draw sprites
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); // use additive alpha blending for sprites!
    ship->draw();
    // refresh window
    SDL_GL_SwapWindow(window);
}

int SDLCALL watch(void *userdata, SDL_Event* event) {
    if (event->type == SDL_APP_WILLENTERBACKGROUND) {
        quitting = true;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }
    // create an empty window
    window = SDL_CreateWindow("title",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WINDOW_WIDTH, WINDOW_HEIGHT,
            SDL_WINDOW_OPENGL);
    gl_context = SDL_GL_CreateContext(window);
    // get mouse/keyboard/... events
    SDL_AddEventWatch(watch, NULL);
    // setup openGL
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    // Load background sprite
    background = new Image ("data/z_bg_hubble_35.png");
    ship = new Ship ();
    while(!quitting) {
        SDL_Event event;
        while( SDL_PollEvent(&event) ) {
            if(event.type == SDL_QUIT) {
                quitting = true;
            }
        }
        render();
        SDL_Delay(2);
    }

    SDL_DelEventWatch(watch, NULL);
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    exit(0);
}
