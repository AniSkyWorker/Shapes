#pragma once
#include "ShapeView.h"

class CTriangleView : public CAbstractShapeView
{
public:
	CTriangleView(const Vector2d & firstPointPosition, const Vector2d & secondPointPosition, const Vector2d & thirdPointPosition,
		const Color & fillColor, const Color & lineColor);

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	sf::ConvexShape m_triangle;
};

