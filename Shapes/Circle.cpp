#include "stdafx.h"
#include "Circle.h"

std::string CCircle::GetDescription() const
{
	std::string description = "Circle: ";
	description += "<" + m_center.GetDescription() + ","
		+ std::to_string(m_radius) + ">, "
		+ "P=" + std::to_string(GetArea()) + ", "
		+ "S=" + std::to_string(GetPerimeter());
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
