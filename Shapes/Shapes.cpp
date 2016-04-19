#include "stdafx.h"
#include "Point.h"
#include "Shape.h"
#include "Circle.h"
#include "LineSegment.h"

int main()
{
	Color color;
	CPoint point(std::make_pair(1, 0), color);
	CLineSegment line(point, point, color);
	CCircle circle(point, 10 ,color, color);
	std::cout << circle.GetDescription();
    return 0;
}

