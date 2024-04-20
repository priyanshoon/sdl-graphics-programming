#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int main(void) {

    // create a window data type
    SDL_Window* window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL Could Not Be Initialized!\n");
    } else {
        printf("SDL Video systummmm is ready to go!\n");
    }

    window = SDL_CreateWindow("C Window using SDL",
                              0, 0, 640, 480, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("its over for you my friend %s\n", SDL_GetError());
        return 1;
    }

    // Infite loop for application

    bool gameIsRunning = true;
    while (gameIsRunning) {
        SDL_Event event;
        // start out event loop
        while (SDL_PollEvent(&event)) {
            // handle each specific events
            if (event.type == SDL_QUIT) {
                gameIsRunning = false;
            }
            if (event.type == SDL_MOUSEMOTION) {
                printf("Mouse is moving mf!!!\n");
            }
            if (event.type == SDL_KEYDOWN) {
                printf("down the key mf!!!\n");
                if (event.key.keysym.sym == SDLK_0) {
                    printf("0 is pressed!!\n");
                } else {
                    printf("0 is not pressed!!\n");
                }
            }
        }
    }

    SDL_Delay(3000);
    SDL_DestroyWindow(window);


    SDL_Quit();
    return 0;
}
