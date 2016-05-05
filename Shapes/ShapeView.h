#pragma once
#include "Shape.h"

class CAbstractShapeView : public sf::Drawable
{
public:
	virtual ~CAbstractShapeView() = default;
};

namespace
{
	sf::Color GetColor(const Color & color)
	{
		return sf::Color(color.r, color.g, color.b);
	}

	sf::Vector2f ToSfVector(const Vector2d & vec)
	{
		return sf::Vector2f(static_cast<float>(vec.x), static_cast<float>(vec.y));
	}
}

