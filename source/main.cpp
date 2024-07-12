#include <iostream>
#include "SDL3/SDL.h"

int main() {
    SDL_Init(0);
    SDL_Window* window = SDL_CreateWindow("TestEngine", 920, 540, 0);

    return 0;
}
