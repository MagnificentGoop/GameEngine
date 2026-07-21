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

    //TEMP SOUND STUFF
    
    std::vector<FMOD::Sound*> sounds;
    FMOD::Sound* sound = nullptr;

    bad::g_audio->createSound("sounds/alert.mp3", FMOD_DEFAULT, 0, &sound); sounds.push_back(sound);
    bad::g_audio->createSound("sounds/duck-toy.mp3", FMOD_DEFAULT, 0, &sound); sounds.push_back(sound);
    bad::g_audio->createSound("sounds/error.mp3", FMOD_DEFAULT, 0, &sound); sounds.push_back(sound);
    bad::g_audio->createSound("sounds/hee-hee.mp3", FMOD_DEFAULT, 0, &sound); sounds.push_back(sound);
    bad::g_audio->createSound("sounds/mario.mp3", FMOD_DEFAULT, 0, &sound); sounds.push_back(sound);
    bad::g_audio->createSound("sounds/oof.mp3", FMOD_DEFAULT, 0, &sound); sounds.push_back(sound);
    bad::g_audio->createSound("sounds/scream.mp3", FMOD_DEFAULT, 0, &sound); sounds.push_back(sound);
    bad::g_audio->createSound("sounds/whistle.mp3", FMOD_DEFAULT, 0, &sound); sounds.push_back(sound);

    //TEMP SOUND STUFF

    //INITIALIZATION*/

    while (!bad::g_engine.GetIfQuit()) {
        //UPDATE*/
        scene.Update();
        //UPDATE/*
      
        //RENDER*/
        scene.Draw();
        //RENDER/*

        //TEMP SOUND STUFF

        if (bad::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_1)) bad::g_audio->playSound(sounds[0], nullptr, false, nullptr);
        if (bad::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_2)) bad::g_audio->playSound(sounds[1], nullptr, false, nullptr);
        if (bad::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_3)) bad::g_audio->playSound(sounds[2], nullptr, false, nullptr);
        if (bad::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_4)) bad::g_audio->playSound(sounds[3], nullptr, false, nullptr);
        if (bad::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_5)) bad::g_audio->playSound(sounds[4], nullptr, false, nullptr);
        if (bad::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_6)) bad::g_audio->playSound(sounds[5], nullptr, false, nullptr);
        if (bad::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_7)) bad::g_audio->playSound(sounds[6], nullptr, false, nullptr);
        if (bad::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_8)) bad::g_audio->playSound(sounds[7], nullptr, false, nullptr);

        //TEMP SOUND STUFF
    }
    return 0;
}