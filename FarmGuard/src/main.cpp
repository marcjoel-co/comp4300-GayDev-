#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>  // SDL3_image header
#include "keyEvents.h"

// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float PLAYER_SPEED = 100.0f;  // Pixels per second

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

  
    std::cout << "SUCCESS: IMG_Init() for PNGs." << std::endl;

    // Create window
    window = SDL_CreateWindow("Project FarmGuard", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
    if (window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, nullptr);
    if (renderer == nullptr) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

      SDL_Texture* texture = IMG_LoadTexture(renderer, "assets/free/free.png");
    if (texture == nullptr) {
        std::cout << "FAIL: IMG_LoadTexture failed: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }


    bool running = true;
    SDL_Event e;

    // Player rectangle
    SDL_FRect playerRect;
    playerRect.x = 100.0f;
    playerRect.y = 50.0f;
    playerRect.w = 32.0f;
    playerRect.h = 64.0f;

   
    Uint64 previousTime = SDL_GetTicks();
    while (running) {
        // 1. Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_EVENT_QUIT) {
                running = false;
            }
            // Add ESC key to exit fullscreen easily
            if (e.type == SDL_EVENT_KEY_DOWN) {
                if (e.key.key == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }

        // Get the current keyboard state
        int numKeys;  // Will hold the number of keys
        const bool* keystate = SDL_GetKeyboardState(&numKeys);  
        
        MoveDirection dir = handleKeyDown(keystate);
        
        // Calculate delta time in seconds
        Uint64 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - previousTime) / 1000.0f;
        previousTime = currentTime;

        // Handle movement with delta time
        switch (dir) {
            case MoveDirection::UP:    
                playerRect.y -= PLAYER_SPEED * deltaTime; 
                break;
            case MoveDirection::DOWN:  
                playerRect.y += PLAYER_SPEED * deltaTime; 
                break;
            case MoveDirection::LEFT:  
                playerRect.x -= PLAYER_SPEED * deltaTime; 
                break;
            case MoveDirection::RIGHT: 
                playerRect.x += PLAYER_SPEED * deltaTime; 
                break;
            case MoveDirection::UP_LEFT:    
                playerRect.y -= PLAYER_SPEED * deltaTime * 0.707f; 
                playerRect.x -= PLAYER_SPEED * deltaTime * 0.707f; 
                break;
            case MoveDirection::UP_RIGHT:   
                playerRect.y -= PLAYER_SPEED * deltaTime * 0.707f; 
                playerRect.x += PLAYER_SPEED * deltaTime * 0.707f; 
                break;
            case MoveDirection::DOWN_LEFT:  
                playerRect.y += PLAYER_SPEED * deltaTime * 0.707f; 
                playerRect.x -= PLAYER_SPEED * deltaTime * 0.707f; 
                break;
            case MoveDirection::DOWN_RIGHT: 
                playerRect.y += PLAYER_SPEED * deltaTime * 0.707f; 
                playerRect.x += PLAYER_SPEED * deltaTime * 0.707f; 
                break;
            default: break;
        }

        // 2. Update game state
        // (Nothing to update yet)

        // 3. Render
        // Set background color (yellow-ish)
        SDL_SetRenderDrawColor(renderer, 255, 254, 50, 255);
        SDL_RenderClear(renderer);

        // Render the texture instead of a colored rectangle
        SDL_RenderTexture(renderer, texture, nullptr, &playerRect);

        // Present to screen
        SDL_RenderPresent(renderer);
    }

    // --- Cleanup ---
    SDL_DestroyTexture(texture);  // Clean up the texture
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);  // Cleanup SDL_image before exiting
    SDL_Quit();

    return 0;
}