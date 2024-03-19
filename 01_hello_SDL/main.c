#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdbool.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
    // The window we'll be redering to
    SDL_Window* window = NULL;

    // The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL could not Initialize! SDL_ERROR: %s\n", SDL_GetError());
    } else {
        // create window
        // first parameter is title of windows
        // second and third is pos x and y of windows
        // forth and fifth are size/ratio of windows
        // the last argument is flag to detect wether the window created or not
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not load! SDL_Error: %s\n", SDL_GetError());
        } else {
            // get window surface
            screenSurface = SDL_GetWindowSurface(window);

            // Fill the surface black
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));

            // update the surface
            SDL_UpdateWindowSurface(window);

            // Hack to get window to stay up
            SDL_Event e;
            bool quit = false;
            while(quit == false) {
                while(SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
