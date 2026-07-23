#pragma once
#include "Gametime.h"
#include "Actor.h" //Includes Model, Mesh, and transform
#include "Input.h"
#include "Color.h" //includes Color8, ColorF, Vector4, Vector3, and Vector2
#include "Scene.h"
#include "Random.h"
#include "MathUtils.h"
#include <fmod.hpp>
#include "File.h"

#include <iostream>

namespace bad{
	class Engine {
	public:
		static Engine& Get() { static Engine engine; return engine; }

		bool Initialize();
		void Shutdown();

		void Update();

		Input& GetInput() { return m_input; }
		Renderer& GetRenderer() { return m_renderer; }
		bool GetIfQuit() { return m_quit; }
	private:
		Engine() = default;
		Input m_input;
		Renderer m_renderer;

		bool m_quit = false;
		void* m_extradriverdata = nullptr;
	};

	extern Time g_time;
	extern FMOD::System* g_audio;
}