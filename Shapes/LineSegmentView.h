#pragma once
#include "ShapeView.h"

class CLineSegmentView : public CAbstractShapeView
{
public:
	CLineSegmentView(const Vector2d & startPos, const Vector2d & endPos, const Color & color);

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	sf::VertexArray m_lineSegment;
};

