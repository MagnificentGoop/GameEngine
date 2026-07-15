#include "Engine.h"
#include "Player.h"

int main()
{
    //INITIALIZATION/*
    if (!bad::g_engine.Initialize()) return 1;

    //Initializing Player
    bad::Color8 color{ 255,255,255 };
    std::vector<bad::Vector2<float>> points{ {3,0},{-2,2},{-1,0 }, {-2, -2 }, {3, 0 }};
    bad::Model model;
    model.AddMesh(bad::Mesh{ points, color });
    Player player{bad::Transform2D(bad::Vector2<float>(bad::g_engine.GetRenderer().GetWidth() / 2, bad::g_engine.GetRenderer().GetHeight() / 2), 0.0f, bad::Vector2<float>(7.0f, 7.0f)), model};

    //INITIALIZATION*/

    while (!bad::g_engine.GetIfQuit()) {
        //UPDATE*/
        player.Update();
        //UPDATE/*
        //RENDER*/
        player.Draw();
        bad::g_engine.Update();
        //RENDER/*
    }
    return 0;
}