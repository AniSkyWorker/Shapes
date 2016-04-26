#include "stdafx.h"
#include "TriangleView.h"

CTriangleView::CTriangleView(const Vector2d & firstPointPosition, const Vector2d & secondPointPosition, const Vector2d & thirdPointPosition, const Color & fillColor, const Color & lineColor)
{
	m_triangle.setPointCount(3);
	m_triangle.setPoint(0, sf::Vector2f(firstPointPosition.x, firstPointPosition.y));
	m_triangle.setPoint(1, sf::Vector2f(secondPointPosition.x, secondPointPosition.y));
	m_triangle.setPoint(2, sf::Vector2f(thirdPointPosition.x, thirdPointPosition.y ));
	m_triangle.setOutlineColor(GetColor(lineColor));
	m_triangle.setOutlineThickness(1.f);
	m_triangle.setFillColor(GetColor(fillColor));
}

void CTriangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_triangle, states);
}
