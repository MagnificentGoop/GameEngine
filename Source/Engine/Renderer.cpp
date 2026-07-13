#include <iostream>
#include "Renderer.h"

namespace bad
{
    /// <summary>
    /// Initializes the render engine
    /// </summary>
    /// <param name="name">Name of the window made</param>
    /// <param name="width">Width of the screen wanted</param>
    /// <param name="height">Height of the screen wanted</param>
    /// <returns>1 if error occoured</returns>
    bool Renderer::Initialize(const char* name, const float width, const float height) {
        SDL_Init(SDL_INIT_VIDEO);

        m_window = SDL_CreateWindow(name, (int)width, (int)height, 0);
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

        m_size = new Vector2{ width, height };

        SDL_SetRenderVSync(m_renderer, 1);
        
        SetBackgroundColor(15, 15, 15);
        SetColor(255, 40, 40);
        return 0;
	}

    void Renderer::SetTempColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha){
        SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
    }
    void Renderer::SetTempColor(Color8& c) {
        SDL_SetRenderDrawColor(m_renderer, c.r, c.g, c.b, c.a);
    }
    void Renderer::SetTempColor(ColorF& c) {
        SDL_SetRenderDrawColor(m_renderer, c.r, c.g, c.b, c.a);
    }

    void Renderer::SetColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha) {
        if (Color != nullptr) {
            delete Color;
            Color = nullptr;
        }
        Color = new Color8(red, green, blue, alpha);
    }
    void Renderer::SetColor(Color8& c) {
        if (Color != nullptr) {
            delete Color;
            Color = nullptr;
        }
        Color = new Color8(c.r, c.g, c.b, c.a);
    }
    void Renderer::SetColor(ColorF& c) {
        if (Color != nullptr) {
            delete Color;
            Color = nullptr;
        }
        Color = new Color8(c.r, c.g, c.b, c.a);
    }

    void Renderer::SetBackgroundColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha) {
        if (backgroundColor != nullptr) {
            delete backgroundColor;
            backgroundColor = nullptr;
        }
        backgroundColor = new Color8(red, green, blue, alpha);
    }
    void Renderer::SetBackgroundColor(Color8& c) {
        if (backgroundColor != nullptr) {
            delete backgroundColor;
            backgroundColor = nullptr;
        }
        backgroundColor = new Color8(c.r, c.g, c.b, c.a);
    }
    void Renderer::SetBackgroundColor(ColorF& c) {
        if (backgroundColor != nullptr) {
            delete backgroundColor;
            backgroundColor = nullptr;
        }
        backgroundColor = new Color8(c.MakeColor8());
    }

	void Renderer::Clear(){
        SetTempColor(*backgroundColor);
        SDL_RenderClear(m_renderer);
    }
	void Renderer::DrawPoint(float x, float y) {
        ChangeCurrentColor();
		SDL_RenderPoint(m_renderer, x, y);
	}
    void Renderer::DrawRect(float x, float y, float width, float height, bool shouldFill) {
        ChangeCurrentColor();
		SDL_FRect rect{ x, y, width, height };
        if (shouldFill) {
			SDL_RenderFillRect(m_renderer, &rect);
        }
        else {
            SDL_RenderRect(m_renderer, &rect);
        }
    }
    void Renderer::DrawLine(float x1, float y1, float x2, float y2) {
        ChangeCurrentColor();
		SDL_RenderLine(m_renderer, x1, y1, x2, y2);
    }
    void Renderer::DrawText(const char* text, float x, float y, int fontSize, const char* fontPath) {
		if (fontPath == nullptr) {
			fontPath = "C:/Windows/Fonts/Calibri/calibri.ttf"; // Default font path
		}
        ChangeCurrentColor();
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