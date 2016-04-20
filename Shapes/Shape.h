#pragma once

typedef std::pair<double, double> Vector2d;

struct Color
{
	explicit Color(unsigned r, unsigned g, unsigned b) : r(r), g(g), b(b) {}
	Color() : r(0), g(0), b(0) {}

	unsigned r;
	unsigned g;
	unsigned b;
};

class IShape
{
public:
	virtual ~IShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string GetDescription() const = 0;
	virtual Color GetLineColor() const = 0;
};

class CAbstractShape : public IShape
{
public:
	CAbstractShape() = default;
	virtual ~CAbstractShape() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	Color GetLineColor() const override;

protected:
	double m_perimeter = 0;
	double m_area = 0;
	Color m_lineColor;
};
