#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Assets.h"

int main()
{
    //INITIALIZATION/*
    if (!bad::Engine::Get().Initialize()) return 1;

    bad::Scene scene;

    //Initializing Player & Enemy

    PlayerDesc p;
    EnemyDesc e1;
    p.actorDesc.sceneObject.model = Assets::playerModel;
    e1.enemyDesc.sceneObject.model = Assets::playerModel;
    p.actorDesc.sceneObject.name = "Player";
    e1.enemyDesc.sceneObject.name = "E1";
    p.actorDesc.speed = 1000.0f;
    e1.enemyDesc.speed = 1000.0f;
    p.actorDesc.sceneObject.transform = { {0,bad::Engine::Get().GetRenderer().GetHeight() / 2},0,{5,5} };



    Player* player = new Player{p};


    scene.AddSceneObject(player);

    for (int i = 0; i < 100; i++)
    {
        e1.enemyDesc.sceneObject.transform = { {bad::RandomFloat(bad::Engine::Get().GetRenderer().GetWidth()),bad::RandomFloat(bad::Engine::Get().GetRenderer().GetHeight())},bad::RandomFloat(360),{5,5} };
        Enemy* enemy1 = new Enemy{ e1 };
        scene.AddSceneObject(enemy1);
    }

    //INITIALIZATION*/

    while (!bad::Engine::Get().GetIfQuit()) {
        //UPDATE*/
        scene.Update();
        //UPDATE/*
      
        //RENDER*/
        scene.Draw();
        //RENDER/*
    }
    return 0;
}