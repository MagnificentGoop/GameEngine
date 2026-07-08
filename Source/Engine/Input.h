#pragma once
#include <vector>
#include "Vector2.h"
#include <SDL3/SDL.h>
namespace bad {
	class Input {
	public:
		enum MouseButton
		{
			LEFT = 1,
			MIDDLE = 2,
			RIGHT = 3,
			X1 = 4,
			X2 = 5
		};

	public:
		bool Initialize();
		void Shutdown();

		void Update();

		bool GetKeyDown(int key) const { return m_keyStates[key]; }
		bool GetPrevKeyDown(int key) const { return m_prevKeyStates[key]; }
		bool GetKeyPressed(int key) const { return !m_prevKeyStates[key] && m_keyStates[key]; }
		bool GetKeyReleased(int key) const { return m_prevKeyStates[key] && !m_keyStates[key]; }


		bool GetButtonDown(MouseButton button) const { return m_buttonStates & GetButtonBit(button); }
		bool GetPrevButtonDown(MouseButton button) const { return m_prevButtonStates & GetButtonBit(button); }
		bool GetButtonPressed(MouseButton button) const { return !GetPrevButtonDown(button) && GetButtonDown(button); }
		bool GetButtonReleased(MouseButton button) const { return GetPrevButtonDown(button) && !GetButtonDown(button); }

		Vector2<float> GetMousePosition() { return m_mousePosition; }
	private:
		uint32_t GetButtonBit(MouseButton button) const { return SDL_BUTTON_MASK(button); }

	private:
		std::vector<bool>m_keyStates;
		std::vector<bool>m_prevKeyStates;

		uint32_t m_buttonStates = 0;
		uint32_t m_prevButtonStates = 0;

		Vector2<float> m_mousePosition;
	};
}