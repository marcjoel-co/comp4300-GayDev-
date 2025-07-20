#include <iostream>
#include <SDL3/SDL.h>
#include <SDL_image.h>

#include "Components.h"
#include "AnimationSystem.h"

// Function to load a texture from a file we will later refactor this in the future
/**
 * @breif Loads a texture from the specified file path.
 * @param path The fiile path to the texture.l
 * @param renderer The SDL_Renderer to use for loading the texture.
 * @return A pointer to the loaded SDL_Texure, or nullptr if it loaded nothing.
 */
SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer) {
    
    SDL_Texture* newTexture = IMG_LoadTexture(renderer, path.c_str());
    if (newTexture == nullptr) {
        std::cout << "Failed to load texture: " << path << " | Error: " << SDL_GetError() << std::endl;
    }
    return newTexture;
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Project FarmGuard", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    //creates sctructure for our components 
    AnimationSystem animationSystem;

    
    TransformComponent seedTransform;
    seedTransform.rect = { 100.0f, 100.0f, 16.0f, 16.0f };

    SpriteComponent seedSprite;
    seedSprite.texture = loadTexture("assets/paperplant/testplant.png", renderer);
    if (!seedSprite.texture) { return 1; } 
    // CORRECTED: Initialize the SDL_FRect
    seedSprite.srcRect = { 0.0f, 0.0f, 16.0f, 16.0f }; // Assuming 16x16 pixel frames

    GrowthAnimationComponent seedAnimation;
    seedAnimation.totalFrames = 6;
    seedAnimation.totalGrowthTime = 10.0f;

    // --- GAME LOOP ---
    bool running = true;
    SDL_Event e;
    // CORRECTED: Use the 64-bit timer function from SDL3
    Uint64 previousTime = SDL_GetTicks();

    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_EVENT_QUIT || (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE)) {
                running = false;
            }
        }

        // --- UPDATE ---
        Uint64 currentTime = SDL_GetTicks(); // CORRECTED: Use 64-bit timer
        float deltaTime = (currentTime - previousTime) / 1000.0f;
        previousTime = currentTime;

        animationSystem.update(seedAnimation, deltaTime);
        seedSprite.srcRect.x = (float)seedAnimation.currentFrame * seedSprite.srcRect.w;

        // --- RENDER ---
        SDL_SetRenderDrawColor(renderer, 50, 120, 50, 255);
        SDL_RenderClear(renderer);

        // The types now match: SDL_RenderTexture(..., &SDL_FRect, &SDL_FRect)
        SDL_RenderTexture(renderer, seedSprite.texture, &seedSprite.srcRect, &seedTransform.rect);

        SDL_RenderPresent(renderer);
    }

    // --- CLEANUP ---
    SDL_DestroyTexture(seedSprite.texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}