#pragma once
#include "Vector4.h"
namespace bad {
	struct Transform {
		Vector2<float> position;
		float rotation;
		float scale;
	};
}