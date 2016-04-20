#include "stdafx.h"
#include "Point.h"
#include "Shape.h"
#include "Circle.h"
#include "LineSegment.h"
#include "Rectangle.h"

int main()
{
	Color color;
	CPoint point(std::make_pair(1, 0), color);
	CPoint point2(std::make_pair(1, 1), color);
	CLineSegment line(point, point2, color);
	CCircle circle(point, 10 ,color, color);
	CRectangle rect(point2, std::make_pair(5, 3), color, color);
	std::cout <<rect.GetDescription() <<std::endl << line.GetDescription() << std::endl<< circle.GetDescription() << std::endl;
    return 0;
}

