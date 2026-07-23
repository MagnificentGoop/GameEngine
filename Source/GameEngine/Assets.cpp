#include "Assets.h"

namespace Assets {
    bad::Color8 color1{ 255,255,255 };
    bad::Color8 color2{ 255,5,5 };
    std::vector<bad::Vector2<float>> points1{ {3,0},{-2,2},{-1,0 }, {-2, -2 }, {3, 0 } };
    std::vector<bad::Vector2<float>> points2{ {-3,0}, {-5,2}, {-5,-2},{-3,0} };
    bad::Model temp{{bad::Mesh(points1, color1), bad::Mesh(points2, color2)}};
    bad::Model playerModel{temp};

}