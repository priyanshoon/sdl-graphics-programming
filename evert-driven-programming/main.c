#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// The window will be redering  to
SDL_Window* gWindow = NULL;

// The surface contain by the window
SDL_Surface* gScreenSurface = NULL;

// The image will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

// starts sdl and create window
bool init() {
    // initialize flag
    bool success = true;

    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        // create window
        gWindow = SDL_CreateWindow("SDL Image Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

// loads media
bool loadMedia() {
    // initialize success flag
    bool success = true;

    // load splash image
    gHelloWorld = SDL_LoadBMP("image.bmp");

    if (gHelloWorld == NULL) {
        printf("unable to load the image %s! SDL Error : %s\n", "image.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

// free media and shuts down sdl
void closeP() {
    // deallocate surface
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    // destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Quit SDL subsystem
    SDL_Quit();
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

            while(!quit) {
                // handle the event on queue
                while (SDL_PollEvent(&e) != 0) {
                    // user request quit
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }

                // apply the image
                SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

                //update the surface
                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }

    closeP();
    return 0;
}
