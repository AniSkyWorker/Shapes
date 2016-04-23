#pragma once
#include "Shape.h"

class ISolidShape : public IShape
{
public:
	virtual ~ISolidShape() = default;
	virtual Color GetFillColor() const = 0;
};

class CAbstractSolidShape : public ISolidShape
{
public:
	CAbstractSolidShape() = default;
	virtual ~CAbstractSolidShape() = default;

	Color GetFillColor() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	Color GetLineColor() const override;

protected:
	double m_perimeter = 0;
	double m_area = 0;
	Color m_lineColor;
	Color m_fillColor;
};