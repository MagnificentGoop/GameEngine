#include "Gametime.h"
namespace bad {
	Time::Time() {
		Reset();
	}

	void Time::Reset() {
		m_startTicks = SDL_GetTicksNS();
		m_frameTicks = SDL_GetTicksNS();
		m_currentTicks = SDL_GetTicksNS();
	}

	void Time::Tick() {
		m_currentTicks = SDL_GetTicksNS();
		m_deltaTicks = m_currentTicks - m_frameTicks;
		m_frameTicks = m_currentTicks;
	}

	//ticks = SDL_GetTicksNS(); //1000 tics/second
//float seconds = (float)ticks / 1'000'000'000;
//float deltaTime = (float)(ticks - prevTicks) / 1'000'000'000;
}