#include "Enemy.h"
#include"DxLib.h"

Enemy::Enemy()
{

	location = Vector2D(600.0f, 50.0f);

	radius = 20;

	//location.x = 600;
	//location.y = 50;
	Xspeed = 10;
	Yspeed  = 10;
	count = 0;


}

Enemy::~Enemy()
{

}

// 処理化処理
void Enemy::Initialize()
{
	
}

void Enemy::Update()
{
	count++;

	if (count >= 1000) count = 0;

	if (count < 500) {
		//仮　縦に反射
		location.y += Yspeed;
		if (location.y < 20) {
			Yspeed *= -1;
		}
		else if (location.y > 500) {
			Yspeed *= -1;
		}
	}
	if (count >= 500) {
		if (50 < location.x) {
			location.x = location.x - 5;
		}
		if (50 > location.x) {
			location.x = location.x + 5;
		}

		if (backflg == 0) {//最初の位置へ戻るときはY軸の移動はしない
			if (300 < location.y) {
				location.y = location.y - 5;

			}
			if (300 > location.y) {
				location.y = location.y + 5;

			}
		}
	}

	//敵を元の位置に戻す
	if (count < 500 && location.x < 500) {
		backflg = 1;
	}
	else {
		backflg = 0;
	}
	if (backflg == 1) {
		location.x = location.x + 10;
	}
}

void Enemy::Draw()const
{
	DrawCircle(location.x, location.y,radius, 0xff0000, 1);

	DrawFormatString(100, 150, 0xffffff, "%d", location.x);

	//仮でプレイヤー
	DrawCircle(50, 300, 10, 0xffffff, 1);
	DrawFormatString(100, 100, 0xffffff, "%d", count);
}

void Enemy::Finalize()
{
}

Vector2D Enemy::GetBoxSize() const
{
	return Vector2D();
}


void Enemy::SetLocation(float x, float y)
{
	this->location = Vector2D(x, y);
}



//位置情報取得処理
Vector2D Enemy::GetLocation() const
{
	return this->location;
}
