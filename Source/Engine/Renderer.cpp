#include <iostream>
#include "Renderer.h"

namespace bad
{
    bool Renderer::Initialize(const char* name, int width, int height) {
        SDL_Init(SDL_INIT_VIDEO);

        m_window = SDL_CreateWindow(name, 1280, 1024, 0);
        if (m_window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        m_renderer = SDL_CreateRenderer(m_window, NULL);
        if (m_renderer == nullptr) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return 1;
        }
	}
    void Renderer::SetColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha){
        SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
    }
	void Renderer::Clear(){
        SDL_RenderClear(m_renderer);
    }
	void Renderer::DrawPoint(float x, float y) {
		SDL_RenderPoint(m_renderer, x, y);
	}
    void Renderer::DrawRect(float x, float y, float width, float height, bool shouldFill) {
		SDL_FRect rect{ x, y, width, height };
        if (shouldFill) {
			SDL_RenderFillRect(m_renderer, &rect);
        }
        else {
            SDL_RenderRect(m_renderer, &rect);
        }
    }
    void Renderer::DrawLine(float x1, float y1, float x2, float y2) {
		SDL_RenderLine(m_renderer, x1, y1, x2, y2);
    }
    void Renderer::DrawText(const char* text, float x, float y, int fontSize, const char* fontPath) {
		if (fontPath == nullptr) {
			fontPath = "C:\Windows\Fonts\Calibri\calibri.ttf"; // Default font path
		}

		SDL_RenderDebugText(m_renderer, x, y, text);
    }
    void Renderer::Render() {
		SDL_RenderPresent(m_renderer);
    }
    void Renderer::DestroyRenderer() {
		SDL_DestroyRenderer(m_renderer);
    }
    void Renderer::DistroyWindow() {
		SDL_DestroyWindow(m_window);
    }
    void Renderer::Quit() {
        DestroyRenderer();
        DistroyWindow();
		SDL_Quit();
    }
}