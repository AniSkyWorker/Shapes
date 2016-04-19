#pragma once
#include "SolidShape.h"
#include "Point.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(const CPoint & upleftPoint, const Vector2d & widthHeght,const Color & fillColor, const Color & lineColor)
		: m_upleftPoint(upleftPoint), m_widthHeight(widthHeght)
	{
		m_fillColor = fillColor;
		m_lineColor = lineColor;
	}

	virtual std::string GetDescription() const override;
	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;

private:
	CPoint m_upleftPoint;
	Vector2d m_widthHeight;
};
