#include "Bullet.h"
#include "DxLib.h"
#include <math.h>
Bullet::Bullet() : is_active(false), location(0, 0), box_size(0, 0), velocity(0, 0), angle(0), name('\0')
{
}

Bullet::~Bullet()
{

}

void Bullet::Initialize(Vector2D loc, float _angle, char _name)
{
	location = loc;
	box_size = Vector2D(8.0f, 8.0f);
	angle = (_angle * (float)DX_PI * 2) / 360;
	name = _name;
}

void Bullet::Update()
{
	velocity.x = (1 * cosf(angle));
	velocity.y = (1 * sinf(angle));

	// ˆÚ“®—Ê•ªÀ•W‚ð“®‚©‚·
	location += velocity;
}

void Bullet::Draw() const
{
	DrawBox(location.x, location.y, location.x + box_size.x, location.y + box_size.y, 0xff00ff, true);
}

Vector2D Bullet::GetLocation() const
{
	return this->location;
}
Vector2D Bullet::GetVelocity() const
{
	return this->velocity;
}
Vector2D Bullet::GetBoxSize() const
{
	return this->box_size;
}
float Bullet::GetSpeed() const
{
	return 0.0f;
}


void Bullet::SetLocation(float x, float y)
{

}