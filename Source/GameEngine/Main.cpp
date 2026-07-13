//#include <Engine.h> //temporarily commented out
#include "paint.h"

int main()
{
    //INITIALIZATION/*
    bad::Renderer rend;


//Initilazing window
    bool quit = true;
    for (int count = 0; count < 6; count++)
    {
        quit = rend.Initialize("Window", 1920, 1080);;

        if (count > 4) {
            std::cerr << "SDL failed to create windows multiple times" << std::endl;
            return 1;
        }
        else if (!quit) {
            quit = false;
            break;
        }
    }

    //Initializing input object
    bad::Input input;
    input.Initialize();

    bad::Time time;

    bad::paint paint; //Temporary paint class that holds paint functions

    //INITIALIZATION*/

    while (!quit) {
        //UPDATE*/
        SDL_Event event;
        rend.Clear();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        input.Update();
        paint.Update(input); //Temporary 
        //UPDATE/*

        //RENDER*/
        paint.Render(rend); //Temporary 
        rend.Render();
        //RENDER/*
    }
    //SHUTDOWN/*
    rend.Quit();

    return 0;
    //SHUTDOWN*/
}