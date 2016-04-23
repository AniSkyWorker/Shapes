#pragma once
#include "SolidShape.h"

class CCircle : public CAbstractSolidShape
{
public:
	CCircle(const Vector2d & center, const double & radius, const Color & fillColor, const Color & lineColor);

	std::string GetDescription() const override;
	double GetPerimeter() const override;
	double GetArea() const override;

	Vector2d GetCenterPosition() const;
	double GetRadius() const;

private:
	Vector2d m_centerPosition;
	double m_radius;
};