#include "Engine.h"

namespace bad {

	Engine g_engine;
	Time g_time;
	FMOD::System* g_audio;
	bool Engine::Initialize(){
		if (!(m_renderer.Initialize("Window", 1920, 1080) || m_input.Initialize())) {
			return false;
		}
		FMOD::System_Create(&g_audio);
		g_audio->init(32, FMOD_INIT_NORMAL, m_extradriverdata);
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
		g_audio->update();

		if(m_quit) bad::g_engine.Shutdown();
	}
}
