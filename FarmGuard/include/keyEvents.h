// include/keyEvents.h
#pragma once // Prevents the header from being included multiple times

#include <SDL3/SDL_events.h>

enum class MoveDirection {
    NONE, UP, DOWN, LEFT, RIGHT,
    UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT
};

// The function prototype must match the implementation
MoveDirection handleKeyDown(const bool* keystate);