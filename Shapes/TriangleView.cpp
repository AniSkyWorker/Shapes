#include "stdafx.h"
#include "TriangleView.h"

CTriangleView::CTriangleView(const Vector2d & firstPointPosition, const Vector2d & secondPointPosition, const Vector2d & thirdPointPosition, const Color & fillColor, const Color & lineColor)
{
	m_triangle.setPointCount(3);
	m_triangle.setPoint(0, ToSfVector(firstPointPosition));
	m_triangle.setPoint(1, ToSfVector(secondPointPosition));
	m_triangle.setPoint(2, ToSfVector(thirdPointPosition));
	m_triangle.setOutlineColor(GetColor(lineColor));
	m_triangle.setOutlineThickness(1.f);
	m_triangle.setFillColor(GetColor(fillColor));
}

void CTriangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_triangle, states);
}
