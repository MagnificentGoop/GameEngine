#include <Engine.h>


int main()
{
    //INITIALIZATION/*
    bad::Renderer rend;
    rend.SetBackgroundColor(15,15,15); // you NEED to set this initially

//Initilazing window
    bool quit = true;
    for (int count = 0; count < 5; count++)
    {
        quit = rend.Initialize("Window", 800, 800);;

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

    //rendering assignment
    std::vector<bad::Vector2<int>> dots;
    std::vector<bad::Vector4<int>> lines;

    //dots.push_back(bad::Vector2(rend.GetWidth() + 5, rend.GetHeight() + 5));
    //lines.push_back(bad::Vector4((rend.GetWidth() + 5.0f), (rend.GetHeight() + 5.0f), -5.0f -5.0f));
    for (int i = 0; i < 201; i++)
    {
        dots.push_back(bad::Vector2(bad::RandomInt(rend.GetWidth()), bad::RandomInt(rend.GetHeight())));
    }
    for (int i = 0; i < 31; i++)
    {
        lines.push_back(bad::Vector4(bad::RandomInt(rend.GetWidth()), bad::RandomInt(rend.GetHeight()), bad::RandomInt(rend.GetWidth()), bad::RandomInt(rend.GetHeight())));
    }
    //rendering assignment

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

        //rendering assignment
        for (size_t i = 0; i < dots.size(); i++)
        {
            rend.SetColor(255, 40, 40);
            rend.DrawPoint(dots.at(i).x, dots.at(i).y);
        }
        for (size_t i = 0; i < lines.size(); i++)
        {
            rend.DrawLine(lines.at(i).x, lines.at(i).y, lines.at(i).z, lines.at(i).w);
        }
        //rendering assignment 
        //UPDATE/*

        //RENDER*/
        rend.Render();
        //RENDER/*
    }
    //SHUTDOWN/*
    rend.Quit();

    return 0;
    //SHUTDOWN*/
}