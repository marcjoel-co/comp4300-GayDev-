#pragma once
#include <SDL3/SDL.h>

struct TransformComponent 
{
    SDL_FRect rect;
};

struct SpriteComponent 
{
    SDL_Texture* texture = nullptr;
    SDL_FRect srcRect; 
};

struct GrowthAnimationComponent {
    int totalFrames = 1;
    int currentFrame = 0;
    float totalGrowthTime = 5.0f;
    float currentGrowthTime = 0.0f;
    bool isMature = false;
};