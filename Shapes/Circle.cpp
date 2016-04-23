#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(const Vector2d & centerPosition, const double & radius, const Color & fillColor, const Color & lineColor)
	: m_centerPosition(centerPosition), m_radius(radius)
{
	m_fillColor = fillColor;
	m_lineColor = lineColor;
}

std::string CCircle::GetDescription() const
{
	std::string description = "Circle: ";
	description += "<" + std::to_string(m_centerPosition.x) + ":" + std::to_string(m_centerPosition.y) + ","
		+ std::to_string(m_radius) + ">, "
		+ "P=" + std::to_string(GetPerimeter()) + ", "
		+ "S=" + std::to_string(GetArea());
	return description;
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

double CCircle::GetArea() const
{
	return M_PI * std::pow(m_radius, 2);
}

Vector2d CCircle::GetCenterPosition() const
{
	return m_centerPosition;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
