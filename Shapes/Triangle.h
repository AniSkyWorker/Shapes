#pragma once
#include "SolidShape.h"

class CTriangle : public CAbstractSolidShape
{
public:
	CTriangle(const Vector2d & firstPointPosition, const Vector2d & secondPointPosition, const Vector2d & thirdPointPosition,
		const Color & fillColor, const Color & lineColor);

	std::string GetDescription() const override;
	double GetPerimeter() const override;
	double GetArea() const override;

	Vector2d GetFirstPointPosition() const;
	Vector2d GetSecondPointPosition() const;
	Vector2d GetThirdPointPosition() const;

private:
	Vector2d m_firstPointPosition;
	Vector2d m_secondPointPosition;
	Vector2d m_thirdPointPosition;
};