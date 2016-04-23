#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(const Vector2d & upleftPoint, const Vector2d & dimensions, const Color & fillColor, const Color & lineColor)
	: m_pointPosition(upleftPoint), m_dimensions(dimensions)
{
	m_fillColor = fillColor;
	m_lineColor = lineColor;
}


std::string CRectangle::GetDescription() const
{
	std::string description = "Rectangle: ";
	description += "<" + std::to_string(m_pointPosition.x)+ ":" + std::to_string(m_pointPosition.y) + ","
		+ "{width=" + std::to_string(m_dimensions.x) + ",height=" + std::to_string(m_dimensions.y) + "}" + ">, "
		+ "P=" + std::to_string(GetPerimeter()) + ", "
		+ "S=" + std::to_string(GetArea());
	return description;
}

double CRectangle::GetPerimeter() const
{
	return m_dimensions.x * 2 + m_dimensions.y * 2;
}

double CRectangle::GetArea() const
{
	return m_dimensions.x * m_dimensions.y;
}

Vector2d CRectangle::GetPointPosition() const
{
	return m_pointPosition;
}

Vector2d CRectangle::GetDimensions() const
{
	return m_dimensions;
}
