#pragma once
#include "Shape.h"

class CPoint : public CAbstractShape
{
public:
	explicit CPoint(const Vector2d & position, const Color & color = Color());

	std::string GetDescription() const override;
	Vector2d GetPosition() const;

private:
	Vector2d m_position;
};