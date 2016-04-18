#include "stdafx.h"

typedef std::pair<double, double> Vector2d;

struct Color
{
	Color() : R(0), G(0), B(0) {}
	unsigned R;
	unsigned G;
	unsigned B;
};

class IShape
{
public:
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
	virtual std::string ToString() = 0;
	virtual Color GetLineColor() = 0;
};

class ISolidShape : public IShape
{
public:
	virtual Color GetFillColor() = 0;
};

class CShape : public IShape
{
public:
	CShape(): m_perimeter(0), m_area(0), m_lineColor() {}
	
	virtual double GetArea() override;
	virtual double GetPerimeter() override;
	virtual Color GetLineColor() override;

protected:
	double m_perimeter;
	double m_area;
	Color m_lineColor;

};

class CSolidShape : public ISolidShape, public CShape
{
public:
	virtual Color GetFillColor() override;
protected:
	Color m_fillColor;
};

class CPoint : public CShape
{
public:
	CPoint(Vector2d position, Color color) : m_position(position) { m_lineColor = color; }

	virtual std::string ToString() override;
private:
	Vector2d m_position;
};

class CLineSegment : public CShape
{
public:
	CLineSegment(CPoint start, CPoint end, Color color) : m_startPoint(start), m_endPoint(end), m_length(GetLength())
	{
		m_lineColor = color;
	}

	virtual std::string ToString() override;
	virtual double GetPerimeter() override;
private:

	double GetLength();

	CPoint m_startPoint;
	CPoint m_endPoint;
	double m_length;
};

class CRectangle : public CSolidShape
{
public:
	CRectangle(CPoint upleftPoint, Vector2d widthHeght, Color fillColor, Color lineColor)
		: m_upleftPoint(upleftPoint), m_widthHeight(widthHeght)
	{
		m_fillColor = fillColor;
		m_lineColor = lineColor;
	}

	virtual std::string ToString() override;
	virtual double GetPerimeter() override;
	virtual double GetArea() override;
private:
	CPoint m_upleftPoint;
	Vector2d m_widthHeight;
};

class CTriangle : public CSolidShape
{
public:
	CTriangle(CPoint firstPoint, CPoint secondPoint, CPoint thirdPoint,
		CLineSegment firstLine, CLineSegment secondLine, CLineSegment thirdLine,
		Color fillColor, Color lineColor)
		: m_firstPoint(firstPoint), m_secondPoint(firstPoint), m_thirdPoint(thirdPoint),
		m_firstLine(firstLine), m_secondLine(secondLine), m_thirdLine(thirdLine)
	{
		m_fillColor = fillColor;
		m_lineColor = lineColor;
	}

	virtual std::string ToString() override;
	virtual double GetPerimeter() override;
	virtual double GetArea() override;
private:
	CPoint m_firstPoint;
	CPoint m_secondPoint;
	CPoint m_thirdPoint;
	CLineSegment m_firstLine;
	CLineSegment m_secondLine;
	CLineSegment m_thirdLine;
};

class CCircle : public CSolidShape
{
public:
	CCircle(CPoint center, double radius,
		Color fillColor, Color lineColor)
		: m_center(center), m_radius(radius)
	{
		m_fillColor = fillColor;
		m_lineColor = lineColor;
	}

	virtual std::string ToString() override;
	virtual double GetPerimeter() override;
	virtual double GetArea() override;
private:
	CPoint m_center;
	double m_radius;
};

int main()
{
    return 0;
}

