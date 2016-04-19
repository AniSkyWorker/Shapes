#pragma once

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
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string GetDescription() const = 0;
	virtual Color GetLineColor() const = 0;
};

class CShape : public IShape
{
public:
	CShape() : m_perimeter(0), m_area(0), m_lineColor() {}

	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual Color GetLineColor() const override;

protected:
	double m_perimeter;
	double m_area;
	Color m_lineColor;
};
