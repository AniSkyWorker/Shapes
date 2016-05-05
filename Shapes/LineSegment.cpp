#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(const Vector2d & startPos, const Vector2d & endPos, const Color & color)
	: m_startPosition(startPos)
	, m_endPosition(endPos)
{
	m_lineColor = color;
}

std::string CLineSegment::GetDescription() const
{
	std::string description = "LineSegment: ";
	description += "<" + std::to_string(m_startPosition.x) + ":" + std::to_string(m_startPosition.y) + "," + std::to_string(m_endPosition.x) + ":" + std::to_string(m_endPosition.y) + ">, "
		+ "P=" + std::to_string(GetPerimeter());
	return description;
}

double CLineSegment::GetPerimeter() const
{
	return GetLineSegmentLenght(m_startPosition, m_endPosition);
}

Vector2d CLineSegment::GetStartPointPosition() const
{
	return m_startPosition;
}

Vector2d CLineSegment::GetEndPointPosition() const
{
	return m_endPosition;
}
