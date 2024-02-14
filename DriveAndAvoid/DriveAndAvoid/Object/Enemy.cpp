#include "Enemy.h"
#include"DxLib.h"
Enemy::Enemy():location(0.0f), box_size(0.0f)
{


}

Enemy::~Enemy()
{

}

// 処理化処理
void Enemy::Initialize()
{
	location = Vector2D(320.0f, 80.0f);
	box_size = Vector2D(32.0f, 32.0f);

	radius = 20;//半径
	hp = 20;//敵HP

	Xspeed = 10;
	Yspeed = 10;
	count = 0;
	tag = 'e';


	enemy_img = LoadGraph("Resource/images/Enemy1.png");
}

void Enemy::Update()
{
	count++;

	if (count >= 1000) count = 0;

	if (backflg == 0) {//最初の位置へ戻るときはY軸の移動はしない

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
	}
	//プレイヤーに向かってまっすぐ進む
	if (count >= 500) {
		attackflg = 1;
		if (PX + 15< location.x) {
			location.x = location.x - 1;
		}
		if (PX +15 > location.x) {
			location.x = location.x + 1;
		}

			if (PY < location.y) {
				location.y = location.y - 1;

			}
			if (PY > location.y) {
				location.y = location.y + 1;

			}
	}

	//敵を元の位置に戻す
	if (count < 500 && location.x < 600) {
		backflg = 1;
	}
	else {
		backflg = 0;
	}
	if (backflg == 1) {
		location.x = location.x + 10;
		attackflg = 0;
	}

	if (attackflg == 0) {
		PX = playerx;
		PY = playery;
	}


}

void Enemy::Draw()const
{
	//仮・敵
//	DrawCircle(location.x, location.y,radius, 0xff0000, 1); 
	DrawRotaGraph(location.x, location.y, 0.25,0,enemy_img,TRUE);
	//敵のHPバー
	DrawBox(location.x - hp, location.y - 30, location.x  + hp, location.y -25, 0xfff000, TRUE);

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
	playerx = x;
	playery = y;
}



//位置情報取得処理
Vector2D Enemy::GetLocation() const
{
	return this->location;
}
