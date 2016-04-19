#pragma once
#include "Shape.h"

class ISolidShape
{
public:
	virtual Color GetFillColor() = 0;
};

class CSolidShape : public ISolidShape, public CShape
{
public:
	virtual Color GetFillColor() override;

protected:
	Color m_fillColor;
};