#pragma once
#include "Shape.h"

class CLineSegment : public CAbstractShape
{
public:
	CLineSegment(const Vector2d & startPos, const Vector2d & endPos, const Color & color);

	std::string GetDescription() const override;
	double GetPerimeter() const override;

	Vector2d GetStartPointPosition() const;
	Vector2d GetEndPointPosition() const;

private:
	Vector2d m_startPosition;
	Vector2d m_endPosition;
};