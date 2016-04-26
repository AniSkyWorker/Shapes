#pragma once
#include "Shape.h"
#include "ShapeView.h"

class CStreamHandler
{
public:
	CStreamHandler(std::string & input, std::ostream & output);

	bool HandleCommand();
	void PrintShapesSortedByArea() const;
	void PrintShapesSortedByPerimeter() const;
	void DrawShapes() const;

private:
	void PrintInfo(const std::vector<std::shared_ptr<IShape>> & vec) const;

	void AddPoint(std::istringstream & strm);
	void AddLineSegment(std::istringstream & strm);
	void AddCircle(std::istringstream & strm);
	void AddRectangle(std::istringstream & strm);
	void AddTriangle(std::istringstream & strm);

private:
	std::string & m_input;
	std::ostream & m_output;

	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::vector<std::shared_ptr<CAbstractShapeView>> m_shapeViews;
	const std::map<std::string, std::function<void(std::istringstream & args)>> m_actionMap;
};
