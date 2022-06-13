#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"

class Ball
{
public:
	Ball();
	void draw(Graphics& gfx);
	void update();
	bool wallBounce();
	bool paddleBounce(Vec2& pPos, float width);
	Vec2 getPos();
	Vec2 getVel();
	void setVel(Vec2& vel);

private:
	Vec2 pos;
	Vec2 vel;
	int radius = 7;
};