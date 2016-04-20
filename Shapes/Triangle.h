#pragma once
#include "SolidShape.h"
#include "Point.h"
#include "LineSegment.h"

class CTriangle : public CAbstractSolidShape
{
public:
	CTriangle(const CLineSegment & firstLine, const CLineSegment & secondLine, const CLineSegment & thirdLine,
		const Color & fillColor, const Color & lineColor)
		: m_firstLine(firstLine), m_secondLine(secondLine), m_thirdLine(thirdLine)
	{
		m_fillColor = fillColor;
		m_lineColor = lineColor;
	}

	virtual std::string GetDescription() const override;
	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;

private:
	CLineSegment m_firstLine;
	CLineSegment m_secondLine;
	CLineSegment m_thirdLine;
};