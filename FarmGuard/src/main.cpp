#include <iostream>
#include <stdexcept> 
#include <SDL3/SDL.h>

#include "Renderer.h" 
#include "Components.h"
#include "AnimationSystem.h"

int main(int argc, char* argv[]) {
    try {
        
        Renderer renderer("Project FarmGuard", 800, 600);
     
        AnimationSystem animationSystem;
        
        //game object
        TransformComponent seedTransform;
        seedTransform.rect = { 100.0f, 100.0f, 16.0f, 16.0f };

        SpriteComponent seedSprite;
        // Use the renderer's method to load the texture
        seedSprite.texture = renderer.loadTexture("assets/paperplant/testplant.png");
        if (!seedSprite.texture) { 
            return 1; // Exit if texture fails to load
        } 
        seedSprite.srcRect = { 0.0f, 0.0f, 16.0f, 16.0f };

        GrowthAnimationComponent seedAnimation;
        seedAnimation.totalFrames = 6;
        seedAnimation.totalGrowthTime = 10.0f;
        
        
        bool running = true;
        SDL_Event e;
        Uint64 previousTime = SDL_GetTicks();

        while (running) {
            // Event Handling
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_EVENT_QUIT || (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE)) {
                    running = false;
                }
            }

            // Timing
            Uint64 currentTime = SDL_GetTicks();
            float deltaTime = (currentTime - previousTime) / 1000.0f;
            previousTime = currentTime;

            // Update Logic
            animationSystem.update(seedAnimation, deltaTime);
            seedSprite.srcRect.x = (float)seedAnimation.currentFrame * seedSprite.srcRect.w;

            // Rendering - use our new renderer methods
            renderer.clear(); // Clears with the default green color
            renderer.render(seedSprite.texture, &seedSprite.srcRect, &seedTransform.rect);
            renderer.present();
        }

        
        SDL_DestroyTexture(seedSprite.texture);

        
    } catch (const std::runtime_error& e) {
        // This block only executes if the Renderer constructor failed.
        std::cerr << "A fatal error occurred during initialization: " << e.what() << std::endl;
        return 1; 
    }

    return 0; // sumakses
}