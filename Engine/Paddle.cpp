#include "Paddle.h"

Paddle::Paddle()
{
	pos.x = Graphics::ScreenWidth / 2;
	pos.y = Graphics::ScreenHeight - ((Graphics::ScreenHeight / 100) * 10);
}

Paddle::Paddle(Vec2 &pos)
	:
	pos(pos)
{
}

void Paddle::draw(Graphics& gfx)
{
	gfx.DrawRect(pos.x, pos.y, pos.x + width, pos.y + height, Colors::Cyan);
}

void Paddle::update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x-=speed * dt * 60.0f;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x+=speed * dt * 60.0f;
	}
}

bool Paddle::wallBounce()
{

	if (pos.x >= Graphics::ScreenWidth - width)
		pos.x = Graphics::ScreenWidth - width;
	else if (pos.x <= 0)
		pos.x = 0;

	return false;
}

Vec2 Paddle::getPos()
{
	return pos;
}

float Paddle::getwidth()
{
	return width;
}
