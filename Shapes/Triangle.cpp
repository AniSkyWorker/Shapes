#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(const Vector2d & firstPointPosition, const Vector2d & secondPointPosition, const Vector2d & thirdPointPosition,
	const Color & fillColor, const Color & lineColor)
	: m_firstPointPosition(firstPointPosition), m_secondPointPosition(secondPointPosition), m_thirdPointPosition(thirdPointPosition)
{
	m_fillColor = fillColor;
	m_lineColor = lineColor;
}

std::string CTriangle::GetDescription() const
{
	std::string description = "Triangle: ";
	description += "<" + std::to_string(m_firstPointPosition.x) + ":" + std::to_string(m_firstPointPosition.y) + ","
		+ std::to_string(m_secondPointPosition.x) + ":" + std::to_string(m_secondPointPosition.y) + ","
		+ std::to_string(m_thirdPointPosition.x) + ":" + std::to_string(m_thirdPointPosition.y) + ">, "
		+ "P=" + std::to_string(GetPerimeter()) + ", "
		+ "S=" + std::to_string(GetArea());
	return description;
}

double CTriangle::GetPerimeter() const
{
	return GetLineSgmentLenght(m_firstPointPosition, m_secondPointPosition)
		+ GetLineSgmentLenght(m_secondPointPosition, m_thirdPointPosition)
		+ GetLineSgmentLenght(m_firstPointPosition, m_thirdPointPosition);
}

double CTriangle::GetArea() const
{
	double halfPerimeter = GetPerimeter() / 2;
	return std::sqrt(halfPerimeter
		* (halfPerimeter - GetLineSgmentLenght(m_firstPointPosition, m_secondPointPosition))
		* (halfPerimeter - GetLineSgmentLenght(m_secondPointPosition, m_thirdPointPosition))
		* (halfPerimeter - GetLineSgmentLenght(m_firstPointPosition, m_thirdPointPosition)));
}

Vector2d CTriangle::GetFirstPointPosition() const
{
	return m_firstPointPosition;
}

Vector2d CTriangle::GetSecondPointPosition() const
{
	return m_secondPointPosition;
}

Vector2d CTriangle::GetThirdPointPosition() const
{
	return m_thirdPointPosition;
}
