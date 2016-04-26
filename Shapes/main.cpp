#include "stdafx.h"
#include "StreamHandler.h"

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

	handler.PrintShapesSortedByPerimeter();

	std::cout << std::endl;

	handler.PrintShapesSortedByArea();

	handler.DrawShapes();
	return 0;
}

