#include "stdafx.h"
#include "StreamHandler.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Point.h"
#include "LineSegmentView.h"
#include "RectangleView.h"
#include "CircleView.h"
#include "TriangleView.h"

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
		{ "point", bind(&CStreamHandler::AddPoint, this, std::placeholders::_1) },
		{ "line", bind(&CStreamHandler::AddLineSegment, this, std::placeholders::_1) },
		{ "circle", bind(&CStreamHandler::AddCircle, this, std::placeholders::_1) },
		{ "rectangle", bind(&CStreamHandler::AddRectangle, this, std::placeholders::_1) },
		{ "triangle", bind(&CStreamHandler::AddTriangle, this, std::placeholders::_1) }
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

void CStreamHandler::PrintInfo(const std::vector<std::shared_ptr<IShape>> & arr) const
{
	for (auto it : arr)
	{
		std::cout << it->GetDescription() << std::endl;
	}
}

void CStreamHandler::PrintShapesSortedByPerimeter() const
{
	auto copyArray = m_shapes;
	std::sort(copyArray.begin(), copyArray.end(), [](const std::shared_ptr<IShape> & shape1, const std::shared_ptr<IShape> & shape2)
	{
		return shape1->GetPerimeter() < shape2->GetPerimeter();
	});

	PrintInfo(copyArray);
}

void CStreamHandler::PrintShapesSortedByArea() const
{
	auto copyArray = m_shapes;
	std::sort(copyArray.begin(), copyArray.end(), [](const std::shared_ptr<IShape> & shape1, const std::shared_ptr<IShape> & shape2)
	{
		return shape1->GetArea() < shape2->GetArea();
	});

	PrintInfo(copyArray);
}

void CStreamHandler::AddPoint(std::istringstream & strm)
{
	Vector2d position;
	strm >> position.x;
	strm >> position.y;

	m_shapes.push_back(std::make_shared<CPoint>(position));
}

void CStreamHandler::AddLineSegment(std::istringstream & strm)
{
	Vector2d firstPoint;
	strm >> firstPoint.x;
	strm >> firstPoint.y;

	Vector2d secondPoint;
	strm >> secondPoint.x;
	strm >> secondPoint.y;

	std::string lineColor;
	strm >> lineColor;

	m_shapes.push_back(std::make_shared<CLineSegment>(firstPoint, secondPoint, GetColor(lineColor)));
	m_shapeViews.push_back(std::make_shared<CLineSegmentView>(firstPoint, secondPoint, GetColor(lineColor)));
}

void CStreamHandler::AddRectangle(std::istringstream & strm)
{
	Vector2d leftUpPoint;
	strm >> leftUpPoint.x;
	strm >> leftUpPoint.y;

	Vector2d dimensions;
	strm >> dimensions.x;
	strm >> dimensions.y;

	std::string lineColor;
	strm >> lineColor;

	std::string fillColor;
	strm >> fillColor;

	m_shapes.push_back(std::make_shared<CRectangle>(leftUpPoint, dimensions, GetColor(fillColor), GetColor(lineColor)));
	m_shapeViews.push_back(std::make_shared<CRectangleView>(leftUpPoint, dimensions, GetColor(fillColor), GetColor(lineColor)));
}

void CStreamHandler::AddCircle(std::istringstream & strm)
{
	Vector2d position;
	strm >> position.x;
	strm >> position.y;

	double radius;
	strm >> radius;

	std::string lineColor;
	strm >> lineColor;

	std::string fillColor;
	strm >> fillColor;

	m_shapes.push_back(std::make_shared<CCircle>(position, radius, GetColor(fillColor), GetColor(lineColor)));
	m_shapeViews.push_back(std::make_shared<CCircleView>(position, radius, GetColor(fillColor), GetColor(lineColor)));
}

void CStreamHandler::AddTriangle(std::istringstream & strm)
{
	Vector2d topVertexPos;
	strm >> topVertexPos.x;
	strm >> topVertexPos.y;

	Vector2d leftVertexPos;
	strm >> leftVertexPos.x;
	strm >> leftVertexPos.y;

	Vector2d rightVertexPos;
	strm >> rightVertexPos.x;
	strm >> rightVertexPos.y;

	std::string lineColor;
	strm >> lineColor;

	std::string fillColor;
	strm >> fillColor;

	m_shapes.push_back(std::make_shared<CTriangle>(topVertexPos, leftVertexPos, rightVertexPos, GetColor(fillColor), GetColor(lineColor)));
	m_shapeViews.push_back(std::make_shared<CTriangleView>(topVertexPos, leftVertexPos, rightVertexPos, GetColor(fillColor), GetColor(lineColor)));
}

void CStreamHandler::DrawShapes() const
{
	sf::RenderWindow window;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window.create(sf::VideoMode(640, 640), "Shape Viewer", sf::Style::Default, settings);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		for (auto ptr : m_shapeViews)
		{
			window.draw(*ptr);
		}

		window.display();

	}
}
