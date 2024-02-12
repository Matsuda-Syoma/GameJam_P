#include "Enemy.h"
#include"DxLib.h"

Enemy::Enemy()
{
	radius = 20;

	Xposition = 600;
	Yposition = 50;
	Xspeed = 10;
	Yspeed  = 10;
	time = 0;
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
	time++;

	if (time >= 1000) time = 0;

	if (time < 500) {
		//仮　縦に反射
		Yposition += Yspeed;
		if (Yposition < 20) {
			Yspeed *= -1;
		}
		else if (Yposition > 500) {
			Yspeed *= -1;
		}
	}
	if (time >= 500) {
		if (50 < Xposition) {
			Xposition = Xposition - 5;
		}
		if (50 > Xposition) {
			Xposition = Xposition + 5;
		}
		if (300 < Yposition) {
			Yposition = Yposition - 5;

		}
		if (300 > Yposition) {
			Yposition = Yposition + 5;

		}
	}

}

void Enemy::Draw()const
{
	DrawCircle(Xposition, Yposition,radius, 0xff0000, 1);

	//仮でプレイヤー
	DrawCircle(50, 300, 10, 0xffffff, 1);
	DrawFormatString(100, 100, 0xffffff, "%d", time);
}

void Enemy::Finalize()
{
}

