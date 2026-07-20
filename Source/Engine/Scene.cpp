#include "pch.h"
#include "Scene.h"
#include "Actor.h"

namespace bad {
	void Scene::Update() {
		bad::g_engine.Update();
		for (Actor* actor : m_actors)
		{
			actor->Update();
		}
	}

	void Scene::Draw() {
		g_engine.GetRenderer().Clear();
		for (Actor* actor : m_actors) {
			actor->Draw();
		}
		g_engine.GetRenderer().Render();
	}
}