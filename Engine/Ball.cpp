#include "Ball.h"

Ball::Ball()
{
	pos.x = Graphics::ScreenWidth / 2;
	pos.y = Graphics::ScreenHeight / 2;

	vel.x = 6.5;
	vel.y = 6.5;
}

void Ball::draw(Graphics& gfx)
{
	gfx.DrawCircle(pos.x, pos.y, radius, Colors::Magenta);
}

void Ball::update(float dt)
{
	pos.x += vel.x * dt * 60.0f;
	pos.y += vel.y * dt * 60.0f;
}

bool Ball::wallBounce()
{
	bool bounce = false;
	if (pos.x >= Graphics::ScreenWidth - radius)
	{
		vel.x = -vel.x;
		pos.x = Graphics::ScreenWidth - radius;
		//pos.x -= radius;
		bounce = true;
	}
	if (pos.y >= Graphics::ScreenHeight - radius)
	{
		pos.y = Graphics::ScreenHeight / 2;
		bounce = true;
	}
	if (pos.x <= radius)
	{
		pos.x = radius;
		//pos.x += radius;
		vel.x = -vel.x;
		bounce = true;
	}
	if (pos.y <= radius)
	{
		pos.y = radius;
		//pos.y += radius;
		vel.y = -vel.y;
		bounce = true;
	}

	return bounce;
}

bool Ball::paddleBounce(Vec2& pPos, float width)
{
	if ((pPos.x <= pos.x) && (pPos.y <= pos.y + radius ) && 
		(pPos.x + width >= pos.x) && (pPos.y + 20 >= pos.y - radius ) && 
		(vel.y > 0.0f))
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

void Ball::setPos(Vec2& pos)
{
	this->pos = pos;
}

Vec2 Ball::getVel()
{
	return vel;
}

void Ball::setVel(Vec2& vel)
{
	this->vel = vel;
}
