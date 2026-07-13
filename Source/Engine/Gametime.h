#pragma once
#include <cstdint>

namespace bad {
	class Time
	{
	public:
		Time();

		void Reset();
		void Tick();

		float GetTime() { return TicksToSeconds(m_currentTicks - m_startTicks); }
		float GetDeltaTime() { return TicksToSeconds(m_deltaTicks); }

		float TicksToSeconds(uint64_t ticks) { return (ticks * 1'000'000'000.0f); }
	private:
		uint64_t m_startTicks;
		uint64_t m_currentTicks;
		uint64_t m_frameTicks;
		uint64_t m_deltaTicks;
	};
}