#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float iLeft, float iRight, float iTop, float iBottom);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	bool isOverlappingWith(const Vec2& other) const;

public:
	float left;
	float right;
	float top;
	float bottom;

	bool destroyed = false;
};