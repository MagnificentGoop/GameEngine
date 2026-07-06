#pragma once
#include <SDL3/SDL.h>
#include "Vector2.h"

namespace bad
{
	class Renderer {
		public:
			//TODO getters for window width and height
			inline float GetWidth() { 
				float temp = m_size->x; 
				return temp;
			}
			inline float GetHeight() { 
				float temp =  m_size->y; 
				return temp;
			}
			inline Vector2 GetSize() { 
				return Vector2{ m_size->x, m_size->y }; 
			}

			bool Initialize(const char* name, float width, float height);
			void SetColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);
			void SetColorFloat(float red, float green, float blue, float alpha = 1.0f);

			void Clear();

			void DrawPoint(float x, float y);
			void DrawRect(float x, float y, float width, float height, bool shouldFill = true);
			void DrawRect(const SDL_FRect* rect, bool shouldFill = true) {
				DrawRect(rect->x, rect->y, rect->w, rect->h, shouldFill);
			};
			void DrawLine(float x1, float y1, float x2, float y2);
			void DrawText(const char* text, float x, float y, int fontSize = 32, const char* fontPath = nullptr);

			void Render();
			void DestroyRenderer();
			void DistroyWindow();
			void Quit();

		private:
			SDL_Window* m_window = nullptr;
			SDL_Renderer* m_renderer = nullptr;
			Vector2* m_size = nullptr;
	};
}