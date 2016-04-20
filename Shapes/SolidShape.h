#pragma once
#include "Shape.h"

class ISolidShape
{
public:
	virtual ~ISolidShape() = default;
	virtual Color GetFillColor() const = 0;
};

class CAbstractSolidShape : public ISolidShape, public CAbstractShape
{
public:
	CAbstractSolidShape() = default;
	virtual ~CAbstractSolidShape();

	virtual Color GetFillColor() const override;

protected:
	Color m_fillColor;
};