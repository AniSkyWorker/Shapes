#pragma once
#include "ShapeView.h"

class CCircleView : public CAbstractShapeView
{
public:
	CCircleView(const Vector2d & center, const double & radius, const Color & fillColor, const Color & lineColor);

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	sf::CircleShape m_circle;
};

