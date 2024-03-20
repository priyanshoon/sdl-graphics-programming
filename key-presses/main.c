#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 440;

enum KeyPressSurface {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

// window will be redering to
SDL_Window* gWindow = NULL;

// surface constain by window
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

bool init() {
    // initialize flag
    bool success = true;

    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        // create window
        gWindow = SDL_CreateWindow(
            "SDL Image Tutorial",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );
        if (gWindow == NULL) {
            printf("Window could not load, SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
            // get the window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

// free media and shuts down sdl
void closeP() {
    // destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Quit SDL subsystem
    SDL_Quit();
}

// load individual image
SDL_Surface* loadSurface(char* a) {
    // load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(a);
    if (loadedSurface == NULL) {
        printf("Unable to load the image %s! SDL Error: %s\n", a, SDL_GetError());
    }
    return loadedSurface;
}

// loads media
bool loadMedia() {
    // loading success flag
    bool success = true;

    // load default surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("./press.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL) {
        printf("Failed to load default image!\n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("./up.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL) {
        printf("Failed to load default image!\n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("./down.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL) {
        printf("Failed to load default image!\n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("./left.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL) {
        printf("Failed to load default image!\n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("./right.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL) {
        printf("Failed to load default image!\n");
        success = false;
    }

    return success;
}

int main() {
    printf("SDL Image insertion tutorial\n");
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        if (!loadMedia()) {
            printf("Failed to load media\n");
        } else {
            // hack to get window to stay up
            SDL_Event e;
            bool quit = false;

            // set default current surface
            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

            while(!quit) {
                // handle the event on queue
                while (SDL_PollEvent(&e) != 0) {
                    // user request quit
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    } else if (e.type == SDL_KEYDOWN) {
                        switch (e.key.keysym.sym) {
                            case SDLK_UP:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                            break;

                            case SDLK_DOWN:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                            break;

                            case SDLK_LEFT:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                            break;

                            case SDLK_RIGHT:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                            break;

                            default:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                            break;
                        }
                    }
                }

                //Apply the current image
                SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );

                //Update the surface
                SDL_UpdateWindowSurface( gWindow );
            }
        }
    }

    closeP();
    return 0;
}
