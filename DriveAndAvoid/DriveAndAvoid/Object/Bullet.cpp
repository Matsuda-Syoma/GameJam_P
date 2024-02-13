#include "Bullet.h"
#include "DxLib.h"
Vector2D Bullet::GetLocation() const
{
	return Vector2D();
}
Bullet::Bullet(int ex, int ey)
{
	x = ex;
	y = ey;
}

Bullet::~Bullet()
{

}

void Bullet::Initialize()
{
	Vector2D(bulletx, bullety);
	radius = 2;
	speed = 2;
}

void Bullet::Update()
{
	bulletx = bulletx - speed;
}

void Bullet::Draw() const
{
	//DrawCircle(location.x, location.y, radius, 0x000fff, TRUE);
	DrawFormatString(200, 200,0xffffff, "%d",bulletx);
}


void Bullet::SetLocation(float x, float y)
{
	bulletx = x;
	bullety = y;

}