#include "stdafx.h"
#include "Point.h"

std::string CPoint::GetDescription() const
{
	std::string description = "Point: ";
	description += "<" + std::to_string(m_position.first) + "," + std::to_string(m_position.second) + ">, "
		+ "P=" + std::to_string(GetArea()) + ", " 
		+ "S=" + std::to_string(GetPerimeter());

	return description;
}

Vector2d CPoint::GetPosition()
{
	return m_position;
}
