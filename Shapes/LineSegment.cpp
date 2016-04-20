#include "stdafx.h"
#include "LineSegment.h"

std::string CLineSegment::GetDescription() const
{
	std::string description = "LineSegment: ";
	description += "<" + m_startPoint.GetDescription() + "," + m_endPoint.GetDescription() + ">, "
		+ "P=" + std::to_string(GetPerimeter());
	return description;
}

double CLineSegment::GetPerimeter() const
{
	return m_length;
}

void CLineSegment::SetLength()
{
	Vector2d start = m_startPoint.GetPosition();
	Vector2d end = m_endPoint.GetPosition();

	m_length = std::hypot(end.first - start.first, end.second - start.second);
}
