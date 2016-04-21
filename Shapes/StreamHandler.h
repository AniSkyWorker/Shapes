#pragma once
#include "Shape.h"

class CStreamHandler
{
public:
	CStreamHandler(std::string & input, std::ostream & output);
	bool HandleCommand();
	void PrintSortedBySquareShapes() const;
	void PrintSortedByPerimeterShapes() const;

private:
	void PrintInfoAboutShapes(const std::vector<std::shared_ptr<IShape>> & vec) const;

	void ParsePointArgs(std::istringstream & strm);
	void ParseLineSegmentArgs(std::istringstream & strm);
	void ParseCircleArgs(std::istringstream & strm);
	void ParseRectangleArgs(std::istringstream & strm);
	void ParseTriangleArgs(std::istringstream & strm);

private:
	std::string & m_input;
	std::ostream & m_output;

	std::vector<std::shared_ptr<IShape>> m_shapes;
	const std::map<std::string, std::function<void(std::istringstream & args)>> m_actionMap;
};
