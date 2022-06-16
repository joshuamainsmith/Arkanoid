#include "Brick.h"

Brick::Brick()
{
	for (int y = 0; y < level; y++)
		for (int x = 0; x < nCol; x++)
		{
			brick[y][x].left = x * width;
			brick[y][x].top = y * height + yPad;
			brick[y][x].right = (x * width) + width;
			brick[y][x].bottom = (y * height) + height + yPad;
		}
}

void Brick::draw(Graphics& gfx)
{
	for (int y = 0; y < level; y++)
		for (int x = 0; x < nCol; x++)
		{
			if (!brick[y][x].destroyed)
				gfx.DrawRect(brick[y][x].left+1, brick[y][x].top+1, brick[y][x].right-1, brick[y][x].bottom-1, 
					y % nRow ? (y % nRow == 1 ? Colors::Yellow 
						: 
						(y % nRow == 2 ? Colors::Green 
							: 
							(y % nRow == 3 ? Colors::Blue 
								: 
								Colors::Magenta))) : Colors::Red);
		}
}

bool Brick::isOverlapping(Ball& b)
{
	bool hit = false;
	for (int y = 0; y < nRow; y++)
		for (int x = 0; x < nCol; x++)
		{
			if ((brick[y][x].left < b.getPos().x) && (brick[y][x].top < b.getPos().y) &&
				(brick[y][x].right > b.getPos().x) && (brick[y][x].bottom > b.getPos().y) && (!brick[y][x].destroyed))
			{
				b.setVel(Vec2(b.getVel().x, -b.getVel().y));
				brick[y][x].destroyed = true;
				hit = true;
				break;

			}
		}
	return hit;
}

bool Brick::nextLevel()
{
	for (int y = 0; y < level; y++)
		for (int x = 0; x < nCol; x++)
		{
			if (!brick[y][x].destroyed)
				return false;
		}
	level++;
	level = min(nRow, level);

	return true;
}

void Brick::init(Ball & b, float dt)
{
	for (int y = 0; y < level; y++)
		for (int x = 0; x < nCol; x++)
		{
			brick[y][x].left = x * width;
			brick[y][x].top = y * height + yPad;
			brick[y][x].right = (x * width) + width;
			brick[y][x].bottom = (y * height) + height + yPad;
			brick[y][x].destroyed = false;
		}
	b.setVel(Vec2(b.getVel().x * 60.0f * dt, b.getVel().y * 60.0f * dt));
	b.setPos(Vec2(Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2));
}
