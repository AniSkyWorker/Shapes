#include "stdafx.h"
#include "../Shapes/Rectangle.h"

struct Rectangle_
{
	Color expectedColor;
	double expectedArea = 20;
	double expectedPerimeter = 18;
	Vector2d expectedDimensions;
	Vector2d expectedPointPosition;
	CRectangle rect;

	Rectangle_()
		: expectedDimensions(4, 5)
		, expectedPointPosition(1, 0)
		, rect(expectedPointPosition, expectedDimensions, expectedColor, expectedColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, Rectangle_)

	BOOST_AUTO_TEST_CASE(is_a_solid_shape)
	{
		BOOST_CHECK(static_cast<const ISolidShape*>(&rect));
	}

	BOOST_AUTO_TEST_CASE(is_a_shape)
	{
		BOOST_CHECK(static_cast<const IShape*>(&rect));
	}

	BOOST_AUTO_TEST_CASE(has_a_line_color)
	{
		BOOST_CHECK(AreColorsEqual(static_cast<const CAbstractSolidShape &>(rect).GetLineColor(), expectedColor));
	}

	BOOST_AUTO_TEST_CASE(has_a_fill_color)
	{
		BOOST_CHECK(AreColorsEqual(static_cast<const CAbstractSolidShape &>(rect).GetFillColor(), expectedColor));
	}

	BOOST_AUTO_TEST_CASE(has_an_area)
	{
		BOOST_CHECK_EQUAL(static_cast<const CAbstractSolidShape &>(rect).GetArea(), expectedArea);
	}

	BOOST_AUTO_TEST_CASE(has_a_perimeter)
	{
		BOOST_CHECK_EQUAL(static_cast<const CAbstractSolidShape &>(rect).GetPerimeter(), expectedPerimeter);
	}

	BOOST_AUTO_TEST_CASE(has_a_dimensions)
	{
		BOOST_CHECK(AreVectorsEqual(rect.GetDimensions(), expectedDimensions));
	}

	BOOST_AUTO_TEST_CASE(has_a_point_position)
	{
		BOOST_CHECK(AreVectorsEqual(rect.GetPointPosition(), expectedPointPosition));
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = "Rectangle: <1.000000:0.000000,{width=4.000000,height=5.000000}>, P=18.000000, S=20.000000";
		BOOST_CHECK_EQUAL(static_cast<const CAbstractSolidShape &>(rect).GetDescription(), expectedString);
	}

BOOST_AUTO_TEST_SUITE_END()