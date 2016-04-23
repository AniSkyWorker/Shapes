#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(const Vector2d & position, const Color & color)
	: m_position(position)
{ 
	m_lineColor = color;
}

std::string CPoint::GetDescription() const
{
	std::string description = "Point: ";
	description += "<" + std::to_string(m_position.x) + "," + std::to_string(m_position.y) + ">";

	return description;
}

Vector2d CPoint::GetPosition() const
{
	return m_position;
}