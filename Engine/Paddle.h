#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle();
	Paddle(Vec2 &pos);
	void draw(Graphics &gfx);
	void update(const Keyboard & kbd, float dt);
	bool wallBounce();
	Vec2 getPos();
	float getwidth();

private:
	Vec2 pos;
	Vec2 vel;
	float width = 75;
	float height = 20;
	float speed = 10;

};