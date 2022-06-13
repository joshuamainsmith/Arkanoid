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
	bool nextLevel();
	void init(Ball & b, float dt);

private:
	static int const nCol = 16;
	static int const nRow = 5;
	RectF brick[nRow][nCol];
	float width = 50;
	float height = 20;
	float yPad = 20;
	int level = 1;

};