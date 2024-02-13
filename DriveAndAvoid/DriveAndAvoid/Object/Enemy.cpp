#include "Enemy.h"
#include"DxLib.h"

Enemy::Enemy()
{
	radius = 20;

	Xposition = 600;
	Yposition = 50;
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
		Yposition += Yspeed;
		if (Yposition < 20) {
			Yspeed *= -1;
		}
		else if (Yposition > 500) {
			Yspeed *= -1;
		}
	}
	if (count >= 500) {
		if (50 < Xposition) {
			Xposition = Xposition - 5;
		}
		if (50 > Xposition) {
			Xposition = Xposition + 5;
		}

		if (backflg == 0) {//最初の位置へ戻るときはY軸の移動はしない
			if (300 < Yposition) {
				Yposition = Yposition - 5;

			}
			if (300 > Yposition) {
				Yposition = Yposition + 5;

			}
		}
	}

	//敵を元の位置に戻す
	if (count < 500 && Xposition < 500) {
		backflg = 1;
	}
	else {
		backflg = 0;
	}
	if (backflg == 1) {
		Xposition = Xposition + 10;
	}
}

void Enemy::Draw()const
{
	DrawCircle(Xposition, Yposition,radius, 0xff0000, 1);

	DrawFormatString(100, 150, 0xffffff, "%d", Xposition);

	//仮でプレイヤー
	DrawCircle(50, 300, 10, 0xffffff, 1);
	DrawFormatString(100, 100, 0xffffff, "%d", count);
}

void Enemy::Finalize()
{
}

