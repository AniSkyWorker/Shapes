#include "stdafx.h"
#include "Point.h"

std::string CPoint::GetDescription() const
{
	std::string description = "Point: ";
	description += "<" + std::to_string(m_position.first) + "," + std::to_string(m_position.second) + ">";

	return description;
}

Vector2d CPoint::GetPosition() const
{
	return m_position;
}
