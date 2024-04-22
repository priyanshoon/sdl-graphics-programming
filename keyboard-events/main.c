#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int main(void) {
    SDL_Window *window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("systumm is working!!!\n");
    } else {
        printf("Systumm is not working!!!\n");
    }

    window = SDL_CreateWindow("Keyboard press using sdl", 0, 0, 640, 440, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Systumm is working by systumm under systumm is not working!!\n");
    } else {
        printf("Systum is working and systumm under systumm is working too!!\n");
    }

    bool gameIsRunning = true;
    while (gameIsRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameIsRunning = false;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_0) {
                    printf("0 pressed!!!\n");
                } else {
                    printf("0 not pressed!!!\n");
                }
            }
            const Uint8* state = SDL_GetKeyboardState(NULL);
            if (state[SDL_SCANCODE_RIGHT]) {
                printf("right just pressed!!!\n");
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
