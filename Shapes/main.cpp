#include "stdafx.h"
#include "StreamHandler.h"

//int main()
//{
//	Color color;
//	CPoint point(std::make_pair(1, 0), color);
//	CPoint point2(std::make_pair(1, 1), color);
//	CLineSegment line(point, point2, color);
//	CCircle circle(point, 10 ,color, color);
//	CRectangle rect(point2, std::make_pair(5, 3), color, color);
//	std::cout <<rect.GetDescription() <<std::endl << line.GetDescription() << std::endl<< circle.GetDescription() << std::endl;
//    return 0;
//}

int main(int argc, char *argv[])
{
	std::string line;

	CStreamHandler handler(line, std::cout);

	std::cout << ">> ";
	std::getline(std::cin, line);

	while ((!std::cin.eof()) && (!std::cin.fail()))
	{
		if (!handler.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}

		std::cout << ">> ";
		std::getline(std::cin, line);
	}

	handler.PrintSortedByPerimeterShapes();

	std::cout << std::endl;

	handler.PrintSortedBySquareShapes();

	return 0;
}

