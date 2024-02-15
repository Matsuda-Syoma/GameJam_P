#include "Bullet.h"
#include "DxLib.h"
#include <math.h>
Bullet::Bullet() : is_active(false), velocity(0, 0), angle(0), tag('\0'),image(0)
{
}

Bullet::~Bullet()
{

}

void Bullet::Initialize(Vector2D loc, float _angle, char _tag)
{
	is_active = true;
	location = loc;
	box_size = Vector2D(16.0f, 16.0f);
	angle = (_angle * (float)DX_PI * 2) / 360;
	tag = _tag;

	//画像の読み込み
	image = LoadGraph("Resource/images/bullet.bmp");

	//エラーチェック
	if (image == -1)
	{
		throw("Resource/images/bullet.bmpがありません。\n");
	}
}

void Bullet::Update()
{
	velocity.x = (5 * cosf(angle));
	velocity.y = (5 * sinf(angle));

	// 移動量分座標を動かす
	location += velocity;

	if (location.x < 0) {
		is_active = false;
	}
	if (location.x > 640) {
		is_active = false;
	}
	if (location.y < 0) {
		is_active = false;
	}
	if (location.y > 480) {
		is_active = false;
	}

}

void Bullet::Draw() const
{
	DrawBox(location.x, location.y, location.x + box_size.x, location.y + box_size.y, 0xff00ff, false);
	DrawGraph(location.x, location.y, image, TRUE);
}

bool Bullet::GetActive() const
{
	return this->is_active;
}

void Bullet::SetActive(bool value)
{
	is_active = value;
}

char Bullet::GetTag() const
{
	return this->tag;
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