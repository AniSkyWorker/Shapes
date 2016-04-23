#pragma once

struct Vector2d
{
	explicit Vector2d(double x, double y) : x(x), y(y) {}
	Vector2d() : x(0), y(0) {}

	double x;
	double y;
};

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

namespace
{
	double GetLineSgmentLenght(const Vector2d & first, const Vector2d & second)
	{
		return std::hypot(second.x - first.x, second.y - first.y);
	}

	bool AreColorsEqual(const Color & first, const Color & second)
	{
		return first.r == second.r && first.b == second.b && first.g == second.g;
	}
}