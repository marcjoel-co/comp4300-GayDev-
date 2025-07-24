#include "AnimationSystem.h"
#include <algorithm>
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL_image.h>


void AnimationSystem::update(GrowthAnimationComponent& anim, float deltaTime)
{
    //checks if thge animation is already finished
    if(anim.isMature)
    {
        return;
    }

    //m udpates the currentGrowthTime
    anim.currentGrowthTime += deltaTime;

    // if currentGrowthTime exceeds the totalGrowthTimer, then the plant should be mature now
    if(anim.currentGrowthTime >= anim.totalGrowthTime)
    {
        anim.currentFrame = anim.totalFrames - 1;
        anim.isMature = true;
    }

    else
    {
        float progress = anim.currentGrowthTime / anim.totalGrowthTime;
        anim.currentFrame = static_cast<int> (progress * anim.totalFrames);
        anim.currentFrame = std::min(anim.currentFrame, anim.totalFrames - 1);
    }


}