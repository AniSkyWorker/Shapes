#include "stdafx.h"
#include "../Shapes/LineSegment.h"

struct LineSegment_
{
	Color expectedColor;
	double expectedArea = 0;
	double expectedPerimeter = 3;
	CLineSegment lineSegment;
	LineSegment_()
		: lineSegment(Vector2d(-1, 0), Vector2d(2, 0), expectedColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(LineSegment, LineSegment_)

	BOOST_AUTO_TEST_CASE(is_a_shape)
	{
		BOOST_CHECK(static_cast<const CAbstractShape*>(&lineSegment));
	}

	BOOST_AUTO_TEST_CASE(has_a_color)
	{
		BOOST_CHECK(AreColorsEqual(static_cast<const CAbstractShape &>(lineSegment).GetLineColor(), expectedColor));
	}

	BOOST_AUTO_TEST_CASE(has_an_area_equal_to_zero)
	{
		BOOST_CHECK_EQUAL(static_cast<const CAbstractShape &>(lineSegment).GetArea(), expectedArea);
	}

	BOOST_AUTO_TEST_CASE(has_a_perimeter)
	{
		BOOST_CHECK_EQUAL(static_cast<const CAbstractShape &>(lineSegment).GetPerimeter(), expectedPerimeter);
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = "LineSegment: <-1.000000:0.000000,2.000000:0.000000>, P=3.000000";
		BOOST_CHECK_EQUAL(static_cast<const CAbstractShape &>(lineSegment).GetDescription(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()