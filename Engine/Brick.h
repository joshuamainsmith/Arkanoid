#pragma once

#include "Graphics.h"
#include "RectF.h"
#include "Vec2.h"
#include "Ball.h"

class Brick
{
public:
	Brick();
	void draw(Graphics& gfx);
	bool isOverlapping(Ball & b);

private:
	static int const nCol = 16;
	static int const nRow = 4;
	RectF brick[nRow][nCol];
	float width = 50;
	float height = 20;
	float yPad = 20;

};