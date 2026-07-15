#include "Player.h"
#include "Renderer.h"
#include "Engine.h"

void Player::Update() {
    if (bad::g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_W)) AddVelocity(bad::Vector2<float>{0, -10});
    if (bad::g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_S)) AddVelocity(bad::Vector2<float>{0, 10});
    if (bad::g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_D)) AddRotation(180 * bad::g_time.GetDeltaTime());
    if (bad::g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_A)) AddRotation(-180 * bad::g_time.GetDeltaTime());


    Actor::Update();
}

void Player::Draw() const {
	Actor::Draw();
}
