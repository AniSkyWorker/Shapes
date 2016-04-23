#pragma once
#include "SolidShape.h"

class CRectangle : public CAbstractSolidShape
{
public:
	CRectangle(const Vector2d & upleftPoint, const Vector2d & dimensions, const Color & fillColor, const Color & lineColor);

	std::string GetDescription() const override;
	double GetPerimeter() const override;
	double GetArea() const override;

	Vector2d GetPointPosition() const;
	Vector2d GetDimensions() const;

private:
	Vector2d m_pointPosition;
	Vector2d m_dimensions;
};