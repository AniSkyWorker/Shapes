#pragma once
#include "Shape.h"

class CAbstractShapeView : public sf::Drawable
{
public:
	virtual ~CAbstractShapeView() = default;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

namespace
{
	sf::Color GetColor(const Color & color)
	{
		return sf::Color(color.r, color.g, color.b);
	}
}

