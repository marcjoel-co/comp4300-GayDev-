#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    // This check is just to ensure SDL2 is linked correctly.
    // We don't initialize it yet.
    if (SDL_WasInit(0) != 0) {
        std::cout << "Something is already initialized?" << std::endl;
    }
    
    std::cout << "Milestone 0.1.0: Environment Setup Complete!" << std::endl;
    
    return 0;
}