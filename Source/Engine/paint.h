#include "Engine.h"
#pragma once
namespace bad {
	class paint {
	public:
		paint();
		void Update(bad::Input& input);
		void Render(bad::Renderer& rend);
	private:
		std::vector<std::vector<bad::Vector2<float>*>*>* points;
	};
}