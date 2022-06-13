#include "RectF.h"

// TODO: check overlapping objects
bool RectF::isOverlappingWith(const Vec2& other) const
{
    return false;
}

RectF::RectF(float iLeft, float iRight, float iTop, float iBottom)
    :
    left(iLeft),
    right(iRight),
    top(iTop),
    bottom(iBottom)
{

}

RectF::RectF(const Vec2& topLeft, const Vec2& bottomRight)
    :
    RectF(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

RectF::RectF(const Vec2& topLeft, float width, float height)
    :
    RectF(topLeft, topLeft + Vec2(width, height))
{
}