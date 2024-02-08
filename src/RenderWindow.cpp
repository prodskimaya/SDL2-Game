#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* title, int width, int height)
    : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        std::cout << "Failed to initialize window! Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    if(renderer == NULL)
    {
        std::cout << "Failed to initialize renderer! Error: " << SDL_GetError() << std::endl;
    }
}

void RenderWindow::Clear()
{
    SDL_RenderClear(renderer);
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, filePath);

    if(texture == NULL)
    {
        std::cout << "Failed to load texture from [" << filePath << "] Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        loadedTextures.push_back(texture);
    }

    return texture;
}

void RenderWindow::RenderCopy(SDL_Texture* texture)
{
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void RenderWindow::RenderCopy(SDL_Texture* texture, int x, int y)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;

    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void RenderWindow::Present()
{
    SDL_RenderPresent(renderer);
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyWindow(window);

    if(!loadedTextures.empty())
    {
        for(SDL_Texture* texture : loadedTextures)
        {
            SDL_DestroyTexture(texture);
            std::cout << "Freed a texture." << std::endl;
        }
    }
}