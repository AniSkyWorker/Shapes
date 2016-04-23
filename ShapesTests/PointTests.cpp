#include "stdafx.h"
#include "../Shapes/Point.h"

struct Point_
{
	Color expectedColor;
	double expectedArea = 0;
	double expectedPerimeter = 0;
	CPoint point;
	Point_()
		: point(Vector2d(1.5, -5.5), expectedColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Point, Point_)
	BOOST_AUTO_TEST_CASE(is_a_shape)
	{
		BOOST_CHECK(static_cast<const CAbstractShape*>(&point));
	}

	BOOST_AUTO_TEST_CASE(has_a_color)
	{
		BOOST_CHECK(AreColorsEqual(static_cast<const CAbstractShape &>(point).GetLineColor(), expectedColor));
	}

	BOOST_AUTO_TEST_CASE(has_an_area_equal_to_zero)
	{
		BOOST_CHECK_EQUAL(static_cast<const CAbstractShape &>(point).GetArea(), expectedArea);
	}

	BOOST_AUTO_TEST_CASE(has_a_perimeter_equal_to_zero)
	{
		BOOST_CHECK_EQUAL(static_cast<const CAbstractShape &>(point).GetPerimeter(), expectedPerimeter);
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = "Point: <1.500000,-5.500000>";
		BOOST_CHECK_EQUAL(static_cast<const CAbstractShape &>(point).GetDescription(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()