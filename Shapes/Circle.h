#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public CAbstractSolidShape
{
public:
	CCircle(const CPoint & center, const double & radius,
		const Color & fillColor, const Color & lineColor)
		: m_center(center), m_radius(radius)
	{
		m_fillColor = fillColor;
		m_lineColor = lineColor;
	}

	virtual std::string GetDescription() const override;
	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;

private:
	CPoint m_center;
	double m_radius;
};