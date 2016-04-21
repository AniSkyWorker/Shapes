#include "stdafx.h"
#include "StreamHandler.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

namespace
{
	Color GetColor(const std::string & colors)
	{
		std::istringstream strm(colors);
		int colorValue;
		strm >> std::hex >> colorValue;

		Color color;
		color.r = colorValue / 0x10000;
		color.g = (colorValue / 0x100) % 0x100;
		color.b = colorValue % 0x100;

		return color;
	}

	bool IsUnknownSymbol(const char & symbol)
	{
		return (!isalpha(symbol) && !isspace(symbol) && !isalnum(symbol));
	}
}

CStreamHandler::CStreamHandler(std::string & input, std::ostream & output)
	: m_shapes()
	, m_input(input)
	, m_output(output)
	, m_actionMap
	({
		{ "Point", bind(&CStreamHandler::ParsePointArgs, this, std::placeholders::_1) },
		{ "Line", bind(&CStreamHandler::ParseLineSegmentArgs, this, std::placeholders::_1) },
		{ "Circle", bind(&CStreamHandler::ParseCircleArgs, this, std::placeholders::_1) },
		{ "Rectangle", bind(&CStreamHandler::ParseRectangleArgs, this, std::placeholders::_1) },
		{ "Triangle", bind(&CStreamHandler::ParseTriangleArgs, this, std::placeholders::_1) }
})
{
}

bool CStreamHandler::HandleCommand()
{
	replace_if(m_input.begin(), m_input.end(), IsUnknownSymbol, ' ');
	std::istringstream strm(m_input);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}

	return false;
}

void CStreamHandler::PrintInfoAboutShapes(const std::vector<std::shared_ptr<IShape>> & arr) const
{
	for (auto it : arr)
	{
		std::cout << it->GetDescription() << std::endl;
	}
}

void CStreamHandler::PrintSortedByPerimeterShapes() const
{
	auto copyArray = m_shapes;
	std::sort(copyArray.begin(), copyArray.end(), [](const std::shared_ptr<IShape> & shape1, const std::shared_ptr<IShape> & shape2)
	{
		return shape1->GetPerimeter() < shape2->GetPerimeter();
	});

	PrintInfoAboutShapes(copyArray);
}

void CStreamHandler::PrintSortedBySquareShapes() const
{
	auto copyArray = m_shapes;
	std::sort(copyArray.begin(), copyArray.end(), [](const std::shared_ptr<IShape> & shape1, const std::shared_ptr<IShape> & shape2)
	{
		return shape1->GetArea() < shape2->GetArea();
	});

	PrintInfoAboutShapes(copyArray);
}

void CStreamHandler::ParsePointArgs(std::istringstream & strm)
{
	Vector2d position;
	strm >> position.first;
	strm >> position.second;

	m_shapes.push_back(std::make_shared<CPoint>(position));
}

void CStreamHandler::ParseLineSegmentArgs(std::istringstream & strm)
{
	Vector2d firstPoint;
	strm >> firstPoint.first;
	strm >> firstPoint.second;

	Vector2d secondPoint;
	strm >> secondPoint.first;
	strm >> secondPoint.second;

	std::string lineColor;
	strm >> lineColor;

	m_shapes.push_back(std::make_shared<CLineSegment>(CPoint(firstPoint), CPoint(secondPoint), GetColor(lineColor)));
}

void CStreamHandler::ParseRectangleArgs(std::istringstream & strm)
{
	Vector2d leftUpPoint;
	strm >> leftUpPoint.first;
	strm >> leftUpPoint.second;

	Vector2d dimensions;
	strm >> dimensions.first;
	strm >> dimensions.second;

	std::string lineColor;
	strm >> lineColor;

	std::string fillColor;
	strm >> fillColor;

	m_shapes.push_back(std::make_shared<CRectangle>(CPoint(leftUpPoint), dimensions, GetColor(lineColor), GetColor(fillColor)));
}

void CStreamHandler::ParseCircleArgs(std::istringstream & strm)
{
	Vector2d position;
	strm >> position.first;
	strm >> position.second;

	double radius;
	strm >> radius;

	std::string lineColor;
	strm >> lineColor;

	std::string fillColor;
	strm >> fillColor;

	m_shapes.push_back(std::make_shared<CCircle>(CPoint(position), radius, GetColor(lineColor), GetColor(fillColor)));
}

void CStreamHandler::ParseTriangleArgs(std::istringstream & strm)
{
	Vector2d topVertexPos;
	strm >> topVertexPos.first;
	strm >> topVertexPos.second;

	Vector2d leftVertexPos;
	strm >> leftVertexPos.first;
	strm >> leftVertexPos.second;

	Vector2d rightVertexPos;
	strm >> rightVertexPos.first;
	strm >> rightVertexPos.second;

	std::string lineColor;
	strm >> lineColor;
	Color line = GetColor(lineColor);

	std::string fillColor;
	strm >> fillColor;
	Color fill = GetColor(lineColor);

	m_shapes.push_back(std::make_shared<CTriangle>(CLineSegment(CPoint(topVertexPos), CPoint(leftVertexPos), line)
		, CLineSegment(CPoint(leftVertexPos), CPoint(rightVertexPos), line)
		, CLineSegment(CPoint(rightVertexPos), CPoint(topVertexPos), line)
		, line, fill));
}