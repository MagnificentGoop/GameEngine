#pragma once
#include <SDL3/SDL.h>
#include "Color.h"

namespace bad
{
	class Renderer {
		public:
			inline const float GetWidth() const{ 
				return m_size->x;
			}
			inline const float GetHeight() const{ 
				return m_size->y;
			}
			inline const Vector2<float> GetSize() const{ 
				return Vector2{ m_size->x, m_size->y }; 
			}

			bool Initialize(const char* name, const float width, const float height);
			void SetColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha = 255);
			void SetBackgroundColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha = 255);
			void SetColor(const Color8& c);
			void SetBackgroundColor(const Color8& c);
			void SetColor(const ColorF& c);
			void SetBackgroundColor(const ColorF& c);

			void SetTempColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha = 255);
			void SetTempColor(Color8& c);
			void SetTempColor(ColorF& c);

			void Clear();

			void DrawPoint(const float x, const float y);
			void DrawPoint(const Vector2<float>& p) {
				DrawPoint(p.x, p.y);
			}

			void DrawRect(const float x, const float y, const float width, const float height, const bool shouldFill = false);
			void DrawRect(const Vector4<float>& rect, const bool shouldFill = false) {
				DrawRect(rect.x, rect.y, rect.w, rect.w, shouldFill);
			};
			void DrawRect(const Vector3<float>& rect, const bool shouldFill = false) {
				DrawRect(rect.x, rect.y, rect.s, rect.s);
			}

			void DrawLine(const float x1, const float y1, const float x2, const float y2);
			void DrawLine(const Vector4<float>& l) {
				DrawLine(l.x, l.y, l.z, l.w);
			}
			void DrawLine(const Vector2<float>& pointA, const Vector2<float>& pointB) {
				DrawLine(pointA.x, pointA.y, pointB.x, pointB.y);
			}

			void DrawText(const char* text, const float x, const float y, const int fontSize = 32, const char* fontPath = nullptr);
			void DrawText(const char* text, const Vector2<float>& p, const int fontSize = 32, const char* fontPath = nullptr) {
				DrawText(text, p.x, p.y, fontSize, fontPath);
			}
			void DrawText(const char* text, const Vector3<float>& v, const char* fontPath = nullptr) {
				DrawText(text, v.x, v.y, v.s, fontPath);
			}

			void Render();
			void DestroyRenderer();
			void DistroyWindow();
			void Quit();

	private:
		void ChangeCurrentColor() {
			if (!tempColor) SDL_SetRenderDrawColor(m_renderer, Color->r, Color->g, Color->b, Color->a);
		}

		private:
			SDL_Window* m_window = nullptr;
			SDL_Renderer* m_renderer = nullptr;
			Vector2<float>* m_size = nullptr;

			Color8* backgroundColor = nullptr;
			Color8* Color = nullptr;
			bool tempColor = false;
	};
}