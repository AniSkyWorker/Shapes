#include "stdafx.h"
#include "Triangle.h"
#include "Point.h"
#include "LineSegment.h"

class CTriangle : public CSolidShape
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

std::string CTriangle::GetDescription() const
{
	std::string description = "Triangle: ";
	description += "<" + m_firstLine.GetDescription() + ","
		+ m_secondLine.GetDescription() + ", " + m_secondLine.GetDescription() + ">, "
		+ "P=" + std::to_string(GetArea()) + ", "
		+ "S=" + std::to_string(GetPerimeter());
	return description;
}

double CTriangle::GetPerimeter() const
{
	return m_firstLine.GetPerimeter() + m_secondLine.GetPerimeter() + m_thirdLine.GetPerimeter();
}

double CTriangle::GetArea() const
{
	double halfPerimeter = GetPerimeter() / 2;
	return std::sqrt(halfPerimeter * (halfPerimeter - m_firstLine.GetPerimeter())* (halfPerimeter - m_secondLine.GetPerimeter()) *(halfPerimeter - m_thirdLine.GetPerimeter()));
}
