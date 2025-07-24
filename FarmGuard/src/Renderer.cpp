// Renderer.cpp
#include "Renderer.h"
#include <SDL_image.h>
#include <stdexcept>
#include <iostream>

// The constructor is now much simpler.
Renderer::Renderer(const char* title, int width, int height) : window(nullptr), renderer(nullptr) {
    // SDL_Init now handles everything. No need for IMG_Init.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
    }
    
    // REMOVED the IMG_Init block.

    window = SDL_CreateWindow(title, width, height, 0);
    if (!window) {
        SDL_Quit(); // Only need to quit the main SDL now.
        throw std::runtime_error("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
    }

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        throw std::runtime_error("Renderer could not be created! SDL_Error: " + std::string(SDL_GetError()));
    }
    
    std::cout << "Renderer initialized successfully." << std::endl;
}

// The destructor is also simpler.
Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // REMOVED IMG_Quit().
    SDL_Quit();
    std::cout << "Renderer cleaned up." << std::endl;
}

SDL_Texture* Renderer::loadTexture(const std::string& path) {
    // CHANGE THIS BACK to the correct function name.
    SDL_Texture* newTexture = IMG_LoadTexture(renderer, path.c_str());
    
    if (!newTexture) {
        // Use IMG_GetError() for image-specific errors.
        std::cerr << "Unable to load texture " << path << "! IMG_Error: " << SDL_GetError() << std::endl;
    }
    return newTexture;
}

SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer) 
{
    
    SDL_Texture* newTexture = IMG_LoadTexture(renderer, path.c_str()); //path c_str means that we are converting the string to a c-style string
    

    if (newTexture == nullptr)
    {
        std::cout << "Failed to load texture: " << path << " | Error: " << SDL_GetError() << std::endl;
    }
    return newTexture;
}


// The rest of the functions are unchanged.
void Renderer::clear(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
}

void Renderer::render(SDL_Texture* texture, const SDL_FRect* srcRect, const SDL_FRect* dstRect) {
    SDL_RenderTexture(renderer, texture, srcRect, dstRect);
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}