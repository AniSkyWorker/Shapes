#include "stdafx.h"
#include "CircleView.h"

CCircleView::CCircleView(const Vector2d & center, const double & radius, const Color & fillColor, const Color & lineColor)
{
	m_circle.setPosition(sf::Vector2f(center.x, center.y));
	m_circle.setRadius(radius);
	m_circle.setFillColor(GetColor(fillColor));
	m_circle.setOutlineColor(GetColor(lineColor));
	m_circle.setOutlineThickness(1.f);
}

void CCircleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_circle, states);
}
