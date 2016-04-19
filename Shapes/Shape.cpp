#include "stdafx.h"
#include "Shape.h"

double CShape::GetArea() const
{
	return m_area;
}

double CShape::GetPerimeter() const
{
	return m_perimeter;
}

Color CShape::GetLineColor() const
{
	return m_lineColor;
}
