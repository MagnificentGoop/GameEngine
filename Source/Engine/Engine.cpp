#include "Engine.h"

namespace bad {

	Engine g_engine;
	Time g_time;
	bool Engine::Initialize(){
		if (!(m_renderer.Initialize("Window", 1920, 1080) || m_input.Initialize())) {
			return false;
		}
		return true;
	}
	void Engine::Shutdown(){
		m_renderer.Quit();
	}
	void Engine::Update(){
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				m_quit = true;
			}
		}

		m_input.Update();
		g_time.Tick();
		m_renderer.Render();
		g_engine.GetRenderer().Clear();

		if(m_quit) bad::g_engine.Shutdown();
	}
}
