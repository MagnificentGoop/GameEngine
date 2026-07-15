#pragma once
#include "Actor.h"

class Player : public bad::Actor {
public:
	Player() = default;
	Player(const bad::Transform2D& transform) : Actor(transform) {};
	Player(const bad::Transform2D& transform, const bad::Model& model) : Actor(transform, model) {};

	void Update();
	void Draw() const;


private:
	int m_ammo = 0;
};