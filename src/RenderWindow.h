#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>

class RenderWindow
{
public:
    RenderWindow(const char* title, int width, int height);
    void Clear();
    SDL_Texture* LoadTexture(const char* filePath);
    void RenderCopy(SDL_Texture* texture);
    void RenderCopy(SDL_Texture* texture, int x, int y);
    void Present();
    ~RenderWindow();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SDL_Texture*> loadedTextures;
};