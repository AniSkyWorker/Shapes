#include "stdafx.h"
#include "Rectangle.h"

std::string CRectangle::GetDescription() const
{
	std::string description = "Rectangle: ";
	description += "<" + m_upleftPoint.GetDescription() + "," 
		+ "{width=" + std::to_string(m_widthHeight.first) + ",height=" + std::to_string(m_widthHeight.second) + "}" + ">, "
		+ "P=" + std::to_string(GetPerimeter()) + ", "
		+ "S=" + std::to_string(GetArea());
	return description;
}

double CRectangle::GetPerimeter() const
{
	return m_widthHeight.first * 2 + m_widthHeight.second * 2;
}

double CRectangle::GetArea() const
{
	return m_widthHeight.first * m_widthHeight.second;
}
