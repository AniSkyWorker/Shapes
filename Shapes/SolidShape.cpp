#include "stdafx.h"
#include "SolidShape.h"

Color CAbstractSolidShape::GetFillColor() const
{
	return m_fillColor;
}


double CAbstractSolidShape::GetArea() const
{
	return m_area;
}

double CAbstractSolidShape::GetPerimeter() const
{
	return m_perimeter;
}

Color CAbstractSolidShape::GetLineColor() const
{
	return m_lineColor;
}
