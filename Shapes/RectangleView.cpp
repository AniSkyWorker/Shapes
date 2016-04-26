#include "stdafx.h"
#include "RectangleView.h"

CRectangleView::CRectangleView(const Vector2d & upleftPoint, const Vector2d & dimensions, const Color & fillColor, const Color & lineColor)
{
	m_rectangle.setPosition(sf::Vector2f(upleftPoint.x, upleftPoint.y));
	m_rectangle.setSize(sf::Vector2f(dimensions.x, dimensions.y));
	m_rectangle.setFillColor(GetColor(fillColor));
	m_rectangle.setOutlineColor(GetColor(lineColor));
	m_rectangle.setOutlineThickness(1.f);
}

void CRectangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);
}
