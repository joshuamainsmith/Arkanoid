#include "Ball.h"

Ball::Ball()
{
	pos.x = Graphics::ScreenWidth / 2;
	pos.y = Graphics::ScreenHeight / 2;

	vel.x = 7.5;
	vel.y = 7.5;
}

void Ball::draw(Graphics& gfx)
{
	gfx.DrawCircle(pos.x, pos.y, radius, Colors::Magenta);
}

void Ball::update()
{
	pos.x += vel.x;
	pos.y += vel.y;
}

bool Ball::wallBounce()
{
	bool bounce = false;
	if (pos.x >= Graphics::ScreenWidth - radius  - vel.x)
	{
		vel.x = -vel.x;
		bounce = true;
	}
	if (pos.y >= Graphics::ScreenHeight - radius  - vel.y)
	{
		pos.y = 100;
		bounce = true;
	}
	if (pos.x <= radius  - vel.x)
	{
		vel.x = -vel.x;
		bounce = true;
	}
	if (pos.y <= radius  - vel.y)
	{
		vel.y = -vel.y;
		bounce = true;
	}

	return bounce;
}

bool Ball::paddleBounce(Vec2& pPos, float width)
{
	if ((pPos.x <= pos.x) && (pPos.y <= pos.y + radius ) && (pPos.x + width >= pos.x) && (pPos.y + 20 >= pos.y - radius ))
	{
		vel.y = -vel.y;
		float halfpad = (pPos.x + (width / 2.0f));
		vel.x = (pos.x - halfpad) / 5;
		return true;
	}

	return false;
}

Vec2 Ball::getPos()
{
	return pos;
}

Vec2 Ball::getVel()
{
	return vel;
}

void Ball::setVel(Vec2& vel)
{
	this->vel = vel;
}
