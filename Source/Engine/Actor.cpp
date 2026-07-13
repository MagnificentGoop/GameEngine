#include "pch.h"
#include "Actor.h"
#include "Renderer.h"
#include "MathUtils.h"

namespace bad {
	void Actor::Update(float dt, const Renderer& renderer) {
		m_transform.position += (m_velocity * dt);
		m_velocity *= 0.987f; //drag???

		Clamp(m_transform.position.x, 0.0f, (float)renderer.GetWidth());
		Clamp(m_transform.position.y, 0.0f, (float)renderer.GetHeight());
	}

	void Actor::Draw(const Renderer& renderer) const {

	}
}