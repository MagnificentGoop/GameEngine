#pragma once

#include "Model.h"
#include "Renderer.h"

namespace bad {
	class Actor {
	public:
		Actor() = default;
		Actor(const Transform2D& transform) : m_transform{ transform } {};
		Actor(const Transform2D& transform, const Model& model) :m_transform{ transform }, m_model{ model } {};

		virtual void Update();
		virtual void Draw() const;

		const Transform2D& GetTransoform() { return m_transform; };
		void SetPosition(const Vector2<float>& position) { m_transform.position = position; };
		void SetRotatoin(float rotation) { m_transform.rotation = rotation; };
		float GetRotation() { return m_transform.rotation; }
		void AddRotation(float a) { m_transform.rotation += a; }
		void SetScale(float scale) { m_transform.scale = scale; };
		float GetDrag() { return m_drag; }
		void SetDrag(float drag) { m_drag = drag; }
		Vector2<float> GetVelocity() const { return m_velocity; }
		void SetVelocity(const Vector2<float>& v) { m_velocity = v; }
		void AddVelocity(const Vector2<float>& v) { m_velocity += v; }


	protected:
		Transform2D m_transform;
		Vector2<float> m_velocity{ 0,0 };

		Model m_model;
		float m_drag = 0.988f;
	};
}
