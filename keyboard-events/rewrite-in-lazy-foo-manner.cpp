#include <stdio.h>
#include <SDL2/SDL.h>

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH = 440;

SDL_Window *window = NULL;

bool init();
void closeP();

int main(void) {
    init();
    bool gameIsRunning = true;
    while (gameIsRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameIsRunning = false;
            }
        }
    }
    closeP();
    return 0;
}

bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("the systumm is ready!!!\n");
    } else {
        printf("the systumm is not ready due to error: %s\n", SDL_GetError());
        success = false;
    }

    window = SDL_CreateWindow("Lazyfoo way in sdl", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("It's over for you pyaare!!!\n");
        success = false;
    } else {
        printf("It's not over for you pyaare!!!\n");
    }
    return success;
}

void closeP() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
