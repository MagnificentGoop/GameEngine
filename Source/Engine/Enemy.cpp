#include "Enemy.h"
#include "Player.h"
#include "Renderer.h"
#include "Engine.h"
#include "MathUtils.h"

void Enemy::Update() {
    Player* player = m_scene->GetSceneObjectByName<Player>("Player");
    if (player) {
        bad::Vector2<float> direction = player->GetTransform().position - m_transform.position;
        float rotatoin = direction.Angle();
        SetRotatoin(rotatoin * bad::RadToDeg);

        bad::Vector2<float> forward{ 1,0 };
        forward = forward.Rotate(m_transform.rotation * bad::DegToRad);
        AddVelocity(forward * m_speed * bad::g_time.GetDeltaTime());
    }

    bad::Vector2<float> velocity{ 1,0 };
    velocity = velocity.Rotate(m_transform.rotation * bad::DegToRad) * m_speed * bad::g_time.GetDeltaTime();

    Actor::Update();
}

void Enemy::Draw() const {
    Actor::Draw();
}
