//SDL2 flashing random color example
//Should work on iOS/Android/Mac/Windows/Linux

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

#include <stdlib.h> //rand()
#include <string> //rand()

static bool quitting = false;
static float r = 0.0f;
static SDL_Window *window = NULL;
static SDL_GLContext gl_context;
static GLuint TextureID = 0;
static int width = 1280;
static int height = 720;

GLuint loadImage(const std::string &imgPath) {
    GLuint textureId = 0;
    SDL_Surface* Surface = IMG_Load(imgPath.c_str());
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    int Mode = GL_RGB;
    if(Surface->format->BytesPerPixel == 4) {
        Mode = GL_RGBA;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, Mode,
            Surface->w, Surface->h, 0,
            Mode, GL_UNSIGNED_BYTE, Surface->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return textureId;
}

    void drawImage(GLuint id) {
        glBindTexture( GL_TEXTURE_2D, id );
        glBegin(GL_QUADS);
        // vertex 1
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        // vertex 2
        glTexCoord2f(1.0, 1.0);
        glVertex3f( 1.0f, -1.0f, 0.0f);
        // vertex 3
        glTexCoord2f(1.0, 0.0);
        glVertex3f( 1.0f,  1.0f, 0.0f);
        // vertex 4
        glTexCoord2f(0.0, 0.0);
        glVertex3f(-1.0f,  1.0f, 0.0f);
        glEnd();
    }

    void pushProjection() {
        // setup projection matrix
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        // setup model view matrix
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
    }

    void popProjection() {
        // reset projection matrix
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        // reset model view matrix
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }

    void render() {

        SDL_GL_MakeCurrent(window, gl_context);

            //r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

            glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
            glClear( GL_COLOR_BUFFER_BIT );
            
            // draw the background
            pushProjection();
            drawImage(TextureID);
            popProjection();

        SDL_GL_SwapWindow(window);

    } //render


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

    window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    gl_context = SDL_GL_CreateContext(window);

    SDL_AddEventWatch(watch, NULL);
    
    TextureID = loadImage("data/z_bg_hubble_35.png");
    
    glEnable(GL_TEXTURE_2D);

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

} //main
