#pragma once
#include "Shape.h"

class CPoint : public CShape
{
public:
	CPoint(const Vector2d & position,const Color & color) : m_position(position) { m_lineColor = color; }
	virtual std::string GetDescription() const override;

	Vector2d GetPosition();

private:
	Vector2d m_position;
};