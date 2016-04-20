#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment : public CAbstractShape
{
public:
	CLineSegment(const CPoint & start, const CPoint & end, const Color & color)
		: m_startPoint(start), m_endPoint(end)
	{
		m_lineColor = color;
		SetLength();
	}

	virtual std::string GetDescription() const override;
	virtual double GetPerimeter() const override;

private:
	void SetLength();

	CPoint m_startPoint;
	CPoint m_endPoint;
	double m_length;
};