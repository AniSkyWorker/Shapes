#pragma once
#include "ShapeView.h"

class CRectangleView : public CAbstractShapeView
{
public:
	CRectangleView(const Vector2d & upleftPoint, const Vector2d & dimensions, const Color & fillColor, const Color & lineColor);
	
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	sf::RectangleShape m_rectangle;
};

