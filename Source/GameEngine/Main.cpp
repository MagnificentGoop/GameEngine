#include <Engine.h>


int main()
{
    //INITIALIZATION
    bad::Renderer rend;
    bool quit = true;
    int count = 0;
    do {
        quit = rend.Initialize("Window", 800, 800);
        count++;

        if (count > 4) {
            std::cerr << "SDL Could not create window or renderer too many times" << std::endl;
            return 1;
        }
    } while (quit);

    quit = false;

    std::vector<bad::Vector2> v;

    for (size_t i = 0; i < 300; i++)
    {
        v.push_back(bad::Vector2{ bad::RandomFloat(rend.GetWidth()), bad::RandomFloat(rend.GetHeight()) });
    }


    while (!quit) {
        //UPDATE
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        for (size_t i = 0; i < v.size(); ++i) {
            rend.SetColor(bad::RandomInt(256), bad::RandomInt(256), bad::RandomInt(256));
            rend.DrawPoint(v.at(i).x, v.at(i).y); 
        }

        //RENDER

        rend.SetColor(0, 255, 0, 255);

        rend.SetColor(255, 255, 255, 255);

        rend.Render();
    }
    //SHUTDOWN
    rend.Quit();

    return 0;

}