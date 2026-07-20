#include "Enemy.h"
#include "Renderer.h"
#include "Engine.h"
#include "MathUtils.h"

void Enemy::Update() {
    bad::Vector2<float> velocity{ 1,0 };
    velocity = velocity.Rotate(m_transform.rotation * bad::DegToRad) * m_speed * bad::g_time.GetDeltaTime();

    Actor::Update();
}

void Enemy::Draw() const {
    Actor::Draw();
}
