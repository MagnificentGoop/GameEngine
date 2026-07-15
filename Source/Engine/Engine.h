#pragma once
#include "Gametime.h"
#include "Actor.h" //Includes Model, Mesh, and transform
#include "Input.h"
#include "Color.h" //includes Color8, ColorF, Vector4, Vector3, and Vector2

#include <iostream>

namespace bad{
	class Engine {
	public:
		Engine() = default;

		bool Initialize();
		void Shutdown();

		void Update();

		Input& GetInput() { return m_input; }
		Renderer& GetRenderer() { return m_renderer; }
		bool GetIfQuit() { return m_quit; }
	private:
		Input m_input;
		Renderer m_renderer;

		bool m_quit = false;
	};

	extern Engine g_engine;
	extern Time g_time;
}