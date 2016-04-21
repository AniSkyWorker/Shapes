#pragma once
#include "Shape.h"

class CPoint : public CAbstractShape
{
public:
	CPoint(const Vector2d & position,const Color & color = Color()) : m_position(position) { m_lineColor = color; }
	virtual std::string GetDescription() const override;

	Vector2d GetPosition() const;

private:
	Vector2d m_position;
};