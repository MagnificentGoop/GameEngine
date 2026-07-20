#include "Actor.h"
#include "MathUtils.h"
#include "Engine.h"

namespace bad {
	void Actor::Update() {
		m_transform.position += (m_velocity * bad::g_time.GetDeltaTime());
		m_velocity *= m_drag;

		Wrap(m_transform.position.x, 0.0f, (float)bad::g_engine.GetRenderer().GetWidth());
		Wrap(m_transform.position.y, 0.0f, (float)bad::g_engine.GetRenderer().GetHeight());
	}
}