#include "stdafx.h"
#include "SolidShape.h"

CAbstractSolidShape::~CAbstractSolidShape()
{
}

Color CAbstractSolidShape::GetFillColor() const
{
	return m_fillColor;
}
