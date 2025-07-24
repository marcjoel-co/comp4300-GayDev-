// Renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>
#include <string>

class Renderer {
public:
    // Constructor: Initializes SDL. Throws std::runtime_error on failure.
    Renderer(const char* title, int width, int height);

    // Destructor: Cleans up all SDL resources automatically (RAII).
    ~Renderer();

    // Loads a texture from a file.
    SDL_Texture* loadTexture(const std::string& path);

    // Clears the screen with a specific color.
    void clear(Uint8 r = 50, Uint8 g = 120, Uint8 b = 50, Uint8 a = 255);
    
    // Renders a texture to the screen.
    void render(SDL_Texture* texture, const SDL_FRect* srcRect, const SDL_FRect* dstRect);

    // Presents the rendered frame to the screen.
    void present();

    // Prevent copying to avoid resource management issues.
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif // RENDERER_H