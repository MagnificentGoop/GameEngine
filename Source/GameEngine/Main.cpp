#include "Engine.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
    //INITIALIZATION/*
    if (!bad::g_engine.Initialize()) return 1;

    bad::Scene scene;

    //Initializing Player & Enemy
    bad::Color8 color1{ 255,255,255 };
    bad::Color8 color2{255,5,5};
    std::vector<bad::Vector2<float>> points1{ {3,0},{-2,2},{-1,0 }, {-2, -2 }, {3, 0 }};
    std::vector<bad::Vector2<float>> points2{ {-3,0}, {-5,2}, {-5,-2},{-3,0} };
    bad::Model model;
    model.AddMesh(bad::Mesh{ points1, color1 });
    model.AddMesh(bad::Mesh{ points2, color2 });

    PlayerDesc p;
    EnemyDesc e1;
    EnemyDesc e2;
    p.actorDesc.sceneObject.model = model;
    e1.enemyDesc.sceneObject.model = model;
    e2.enemyDesc.sceneObject.model = model;
    p.actorDesc.sceneObject.name = "Player";
    e1.enemyDesc.sceneObject.name = "E1";
    e2.enemyDesc.sceneObject.name = "E2";
    p.actorDesc.speed = 1000.0f;
    e1.enemyDesc.speed = 1000.0f;
    e2.enemyDesc.speed = 1000.0f;
    p.actorDesc.sceneObject.transform = { {bad::g_engine.GetRenderer().GetWidth() / 2,bad::g_engine.GetRenderer().GetHeight() / 2},0,{5,5} };
    e1.enemyDesc.sceneObject.transform = { {bad::RandomFloat(bad::g_engine.GetRenderer().GetWidth()),bad::RandomFloat(bad::g_engine.GetRenderer().GetHeight())},bad::RandomFloat(360),{5,5}};
    e2.enemyDesc.sceneObject.transform = { {bad::RandomFloat(bad::g_engine.GetRenderer().GetWidth()),bad::RandomFloat(bad::g_engine.GetRenderer().GetHeight())},bad::RandomFloat(360),{5,5}};



    Player* player = new Player{p};
    Enemy* enemy1 = new Enemy{ e1 };
    Enemy* enemy2 = new Enemy{ e2 };

    scene.AddActor(player);
    scene.AddActor(enemy1);
    scene.AddActor(enemy2);
    //INITIALIZATION*/

    while (!bad::g_engine.GetIfQuit()) {
        //UPDATE*/
        scene.Update();
        //UPDATE/*
      
        //RENDER*/
        scene.Draw();
        //RENDER/*
    }
    return 0;
}