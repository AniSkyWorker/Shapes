#include "stdafx.h"
#include "../Shapes/Triangle.h"

struct Triangle_
{
	Color expectedColor;
	double expectedArea = 4.5;
	double expectedPerimeter = 3 + 3 + std::hypot(3, 3);
	Vector2d expectedFirstPointPosition;
	Vector2d expectedSecondPointPosition;
	Vector2d expectedThirdPointPosition;
	CTriangle triangle;
	
	Triangle_()
		: expectedFirstPointPosition()
		, expectedSecondPointPosition(0, 3)
		, expectedThirdPointPosition(3, 0)
		, triangle(expectedFirstPointPosition, expectedSecondPointPosition, expectedThirdPointPosition, expectedColor, expectedColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Triangle, Triangle_)

	BOOST_AUTO_TEST_CASE(is_a_solid_shape)
	{
		BOOST_CHECK(static_cast<const ISolidShape*>(&triangle));
	}
	
	BOOST_AUTO_TEST_CASE(is_a_shape)
	{
		BOOST_CHECK(static_cast<const IShape*>(&triangle));
	}

	BOOST_AUTO_TEST_CASE(has_a_line_color)
	{
		BOOST_CHECK(AreColorsEqual(static_cast<const CAbstractSolidShape &>(triangle).GetLineColor(), expectedColor));
	}

	BOOST_AUTO_TEST_CASE(has_a_fill_color)
	{
		BOOST_CHECK(AreColorsEqual(static_cast<const CAbstractSolidShape &>(triangle).GetFillColor(), expectedColor));
	}

	BOOST_AUTO_TEST_CASE(has_an_area)
	{
		BOOST_CHECK_EQUAL(static_cast<const CAbstractSolidShape &>(triangle).GetArea(), expectedArea);
	}

	BOOST_AUTO_TEST_CASE(has_a_perimeter)
	{
		BOOST_CHECK_EQUAL(static_cast<const CAbstractSolidShape &>(triangle).GetPerimeter(), expectedPerimeter);
	}

	BOOST_AUTO_TEST_CASE(has_a_point_positions)
	{
		BOOST_CHECK(AreVectorsEqual(triangle.GetFirstPointPosition(), expectedFirstPointPosition));
		BOOST_CHECK(AreVectorsEqual(triangle.GetSecondPointPosition(), expectedSecondPointPosition));
		BOOST_CHECK(AreVectorsEqual(triangle.GetThirdPointPosition(), expectedThirdPointPosition));
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = "Triangle: <0.000000:0.000000,0.000000:3.000000,3.000000:0.000000>, P=10.242641, S=4.500000";
		BOOST_CHECK_EQUAL(static_cast<const CAbstractSolidShape &>(triangle).GetDescription(), expectedString);
	}

BOOST_AUTO_TEST_SUITE_END()