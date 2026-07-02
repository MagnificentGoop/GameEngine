#include "SDL3/SDL.h"
#include <Engine.h>

#include <iostream>


int main()
{
    bad::Renderer rend;
    

    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }


        for (int i = 0; i < 1000; ++i) {
            rend.SetColor(rand() % 256, rand() % 256, rand() % 256);
            rend.DrawPoint(rand() % 1280, rand() % 1024);
        }

        rend.SetColor(0, 255, 0, 255);
        rend.DrawRect(&greenSquare);

        rend.SetColor(255, 255, 255, 255);

        rend.Render();
    }

    rend.Quit();

    return 0;

}