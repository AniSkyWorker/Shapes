#include "stdafx.h"
#include "Shape.h"

double CAbstractShape::GetArea() const
{
	return m_area;
}

double CAbstractShape::GetPerimeter() const
{
	return m_perimeter;
}

Color CAbstractShape::GetLineColor() const
{
	return m_lineColor;
}
