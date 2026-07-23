#pragma once
#include <vector>
#include "Engine.h"
namespace bad {
	class Actor;
	class Scene {
	public:
		void AddSceneObject(SceneObject* actor) { actor->m_scene = this; m_objects.push_back(actor); }
		void Update();
		void Draw();

		template<typename T = Actor>
		T* GetSceneObjectByName(const std::string& name);

	private:
		std::vector<SceneObject*> m_objects;
	};

	template<typename T>
	inline T* Scene::GetSceneObjectByName(const std::string& name)
	{
		for (auto object : m_objects) {
			T* objectT = dynamic_cast<T*>(object);
			if (objectT && objectT->m_name == name) {
				return objectT;
			}
		}

	}
}