#include "stdafx.h"
#include "HelpfulFunctions.h"
#include "../Shapes/Circle.h"
#include <iostream>

struct Circle_
{
	Color expectedColor;
	double expectedArea = M_PI * 100;
	double expectedPerimeter = 2 * M_PI * 10;
	CCircle circle;
	Circle_()
		: circle(CPoint({ 0,0 }, expectedColor), 10, expectedColor, expectedColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Circle, Circle_)

BOOST_AUTO_TEST_CASE(is_a_solid_shape)
{
	BOOST_CHECK(static_cast<const CAbstractSolidShape*>(&circle));
}

BOOST_AUTO_TEST_CASE(has_a_line_color)
{
	BOOST_CHECK(AreColorsEqual(static_cast<const CAbstractSolidShape &>(circle).GetLineColor(), expectedColor));
}

BOOST_AUTO_TEST_CASE(has_a_fill_color)
{
	BOOST_CHECK(AreColorsEqual(static_cast<const CAbstractSolidShape &>(circle).GetFillColor(), expectedColor));
}

BOOST_AUTO_TEST_CASE(has_an_area)
{
	BOOST_CHECK_EQUAL(static_cast<const CAbstractSolidShape &>(circle).GetArea(), expectedArea);
}

BOOST_AUTO_TEST_CASE(has_a_perimeter)
{
	BOOST_CHECK_EQUAL(static_cast<const CAbstractSolidShape &>(circle).GetPerimeter(), expectedPerimeter);
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = "Circle: <Point: <0.000000,0.000000>,10.000000>, P=62.831853, S=314.159265";
	BOOST_CHECK_EQUAL(static_cast<const CAbstractSolidShape &>(circle).GetDescription(), expectedString);
}

BOOST_AUTO_TEST_SUITE_END()