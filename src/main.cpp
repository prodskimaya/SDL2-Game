#include <iostream>
#include <SDL2/SDL_image.h>

#include "RenderWindow.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

enum KeyPressSurfaces
{
    KPS_DEFAULT,
    KPS_UP,
    KPS_DOWN,
    KPS_LEFT,
    KPS_RIGHT,
    KPS_RETURN,
    KPS_P,
    KPS_T,
    KPS_TOTAL
};

int main(int arc, char* args[])
{
    RenderWindow window("Game", SCREEN_WIDTH, SCREEN_HEIGHT);

    if(SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL could not initialize! Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    if(!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "SDL Image failed to initialize! Error: " << IMG_GetError() << std::endl;
        return -1;
    }

    SDL_Texture* keyPressSurfaces[KPS_TOTAL];

    keyPressSurfaces[KPS_DEFAULT] = window.LoadTexture("res/default.bmp");
    keyPressSurfaces[KPS_UP] = window.LoadTexture("res/up.bmp");
    keyPressSurfaces[KPS_DOWN] = window.LoadTexture("res/down.bmp");
    keyPressSurfaces[KPS_RIGHT] = window.LoadTexture("res/right.bmp");
    keyPressSurfaces[KPS_LEFT] = window.LoadTexture("res/left.bmp");
    keyPressSurfaces[KPS_T] = window.LoadTexture("res/t.bmp");

    SDL_Texture* currentSurface = keyPressSurfaces[KPS_DEFAULT];

    SDL_Event e;
    bool gameRunning = true;
    while(gameRunning)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                gameRunning = false;
            }
            else if(e.type == SDL_KEYDOWN)
            {
                switch(e.key.keysym.sym)
                {
                    default:
                        currentSurface = keyPressSurfaces[KPS_DEFAULT];
                        break;
                    case SDLK_UP:
                        currentSurface = keyPressSurfaces[KPS_UP];
                        break;
                    case SDLK_DOWN:
                        currentSurface = keyPressSurfaces[KPS_DOWN];
                        break;
                    case SDLK_LEFT:
                        currentSurface = keyPressSurfaces[KPS_LEFT];
                        break;
                    case SDLK_RIGHT:
                        currentSurface = keyPressSurfaces[KPS_RIGHT];
                        break;
                    case SDLK_t:
                        currentSurface = keyPressSurfaces[KPS_T];
                        break;
                }
            }
        }

        window.Clear();
        window.RenderCopy(currentSurface, 0, 0);
        window.Present();
    }
    
    IMG_Quit();
    SDL_Quit();
    return 0;
}