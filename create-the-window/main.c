#include <SDL2/SDL_video.h>
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

    SDL_Delay(3000);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
