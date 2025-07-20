#include "keyEvents.h"


MoveDirection handleKeyDown(const bool* keystate) 
{
    bool up    = keystate[SDL_SCANCODE_UP]    || keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_KP_8];
    bool down  = keystate[SDL_SCANCODE_DOWN]  || keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_KP_2];
    bool left  = keystate[SDL_SCANCODE_LEFT]  || keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_KP_4];
    bool right = keystate[SDL_SCANCODE_RIGHT] || keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_KP_6];
    
    if (up && left)    return MoveDirection::UP_LEFT;
    if (up && right)   return MoveDirection::UP_RIGHT;
    if (down && left)  return MoveDirection::DOWN_LEFT;
    if (down && right) return MoveDirection::DOWN_RIGHT;
    if (up)            return MoveDirection::UP;
    if (down)          return MoveDirection::DOWN;
    if (left)          return MoveDirection::LEFT;
    if (right)         return MoveDirection::RIGHT;
    return MoveDirection::NONE;
}

MoveDirection handleTouchEvent(const SDL_TouchFingerEvent& /*touchEvent*/) {
    // Stub: Implement touch-to-movement mapping if needed
    return MoveDirection::NONE;
}

void handleOtherInput(const SDL_Event& /*e*/) {
    // Stub: Implement as needed for other input types
}