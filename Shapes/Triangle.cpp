#include "stdafx.h"
#include "Triangle.h"

std::string CTriangle::GetDescription() const
{
	std::string description = "Triangle: ";
	description += "<" + m_firstLine.GetDescription() + ","
		+ m_secondLine.GetDescription() + ", " + m_secondLine.GetDescription() + ">, "
		+ "P=" + std::to_string(GetPerimeter()) + ", "
		+ "S=" + std::to_string(GetArea());
	return description;
}

double CTriangle::GetPerimeter() const
{
	return m_firstLine.GetPerimeter() + m_secondLine.GetPerimeter() + m_thirdLine.GetPerimeter();
}

double CTriangle::GetArea() const
{
	double halfPerimeter = GetPerimeter() / 2;
	return std::sqrt(halfPerimeter * (halfPerimeter - m_firstLine.GetPerimeter())* (halfPerimeter - m_secondLine.GetPerimeter()) *(halfPerimeter - m_thirdLine.GetPerimeter()));
}
