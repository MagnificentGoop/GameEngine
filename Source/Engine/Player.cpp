#include "Player.h"
#include "Renderer.h"
#include "Engine.h"
#include "MathUtils.h"

void Player::Update() {
    bad::Vector2<float> velocity{ 1,0 };
    velocity = velocity.Rotate(m_transform.rotation * bad::DegToRad) * m_speed * bad::g_time.GetDeltaTime();

    if (bad::Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_W)) AddVelocity(velocity);
    if (bad::Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_S)) AddVelocity(bad::Vector2<float>{-1,-1} * velocity);
    if (bad::Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_D)) AddRotation(180 * bad::g_time.GetDeltaTime());
    if (bad::Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_A)) AddRotation(-180 * bad::g_time.GetDeltaTime());

    Actor::Update();
}

void Player::Draw() const {
	Actor::Draw();
}
