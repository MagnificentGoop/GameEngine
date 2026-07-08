#pragma once
#include <SDL3/SDL.h>
#include "Color.h"

namespace bad
{
	class Renderer {
		public:
			inline const float GetWidth() { 
				return m_size->x;
			}
			inline const float GetHeight() { 
				return m_size->y;
			}
			inline const Vector2<float> GetSize() { 
				return Vector2{ m_size->x, m_size->y }; 
			}

			bool Initialize(const char* name, const float width, const float height);
			void SetColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha = 255);
			void SetBackgroundColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha = 255);
			void SetColor(Color8& c);
			void SetBackgroundColor(Color8& c);
			void SetColor(ColorF& c);
			void SetBackgroundColor(ColorF& c);

			void Clear();
			void DrawPoint(const float x, const float y);
			void DrawRect(const float x, const float y, const float width, const float height, const bool shouldFill = false);
			void DrawRect(const SDL_FRect* rect, const bool shouldFill = false) {
				DrawRect(rect->x, rect->y, rect->w, rect->h, shouldFill);
			};
			void DrawLine(const float x1, const float y1, const float x2, const float y2);
			void DrawText(const char* text, const float x, const float y, const int fontSize = 32, const char* fontPath = nullptr);

			void Render();
			void DestroyRenderer();
			void DistroyWindow();
			void Quit();

		private:
			SDL_Window* m_window = nullptr;
			SDL_Renderer* m_renderer = nullptr;
			Vector2<float>* m_size = nullptr;

			Color8* backgroundColor = nullptr;
	};
}