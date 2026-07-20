#pragma once
#include <vector>
#include "Engine.h"
namespace bad {
	class Actor;
	class Scene {
	public:
		void AddActor(Actor* actor) { m_actors.push_back(actor); }
		void Update();
		void Draw();

	private:
		std::vector<Actor*> m_actors;
	};
}