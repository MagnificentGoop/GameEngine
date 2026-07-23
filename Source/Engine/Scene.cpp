#include "pch.h"
#include "Scene.h"
#include "Actor.h"

namespace bad {
	void Scene::Update() {
		bad::Engine::Get().Update();
		for (SceneObject* object : m_objects)
		{
			object->Update();
		}
	}

	void Scene::Draw() {
		Engine::Get().GetRenderer().Clear();
		for (SceneObject* object : m_objects) {
			object->Draw();
		}
		Engine::Get().GetRenderer().Render();
	}
}