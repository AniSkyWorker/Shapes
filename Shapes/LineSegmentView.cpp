#include "stdafx.h"
#include "LineSegmentView.h"

CLineSegmentView::CLineSegmentView(const Vector2d & startPos, const Vector2d & endPos, const Color & color)
	:m_lineSegment(sf::Lines, 2)
{
	m_lineSegment[0].position = sf::Vector2f(startPos.x, startPos.y);
	m_lineSegment[1].position = sf::Vector2f(endPos.x, endPos.y);
	m_lineSegment[0].color = GetColor(color);
	m_lineSegment[1].color = GetColor(color);
}

void CLineSegmentView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_lineSegment, states);
}
