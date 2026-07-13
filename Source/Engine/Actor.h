#pragma once
#include "Transform.h"


namespace bad {
	class Actor {
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {};

		void Update(float dt, const class Renderer& renderer);

		void Draw(const class Renderer& render) const;

		const Transform& GetTransoform() { return m_transform; };
		void SetPosition(const Vector2<float>& position) { m_transform.position = position; };
		void SetRotatoin(float rotation) { m_transform.rotation = rotation; };
		void SetScale(float scale) { m_transform.scale = scale; };

	protected:
		Transform m_transform;
		Vector2<float> m_velocity{ 0,0 };
	};
}