#pragma once
#include <SDL3/SDL.h>

namespace bad
{
	class Renderer {
		public:
			bool Initialize(const char* name, int width, int height);
			void SetColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);
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
	};
}