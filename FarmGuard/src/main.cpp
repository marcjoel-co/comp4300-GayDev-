#include <iostream>
// The include path for SDL3 is inside an SDL3 subfolder
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
    // This check ensures SDL3 is linked correctly.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL3 could not be initialized! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::cout << "Milestone 0.1.2: SDL3 Environment Setup Complete!" << std::endl;

    // Don't forget to quit SDL
    SDL_Quit();

    return 0;
}