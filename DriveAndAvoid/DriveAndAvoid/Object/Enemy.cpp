#include "Enemy.h"
#include"DxLib.h"
#include "../Scene/GameMainScene.h"
#include <math.h>

Enemy::Enemy():tag('\0')
{


}

Enemy::~Enemy()
{

}

// 処理化処理
void Enemy::Initialize()
{

	location = Vector2D(600.0f, 80.0f);
	box_size = Vector2D(32.0f, 32.0f);


	radius = 20;//半径
	hp = 10;//敵HP
	hpber = 10;

	Xspeed = 10;
	Yspeed = 5;
	count = 0;
	tag = 'e';


	enemy_img = LoadGraph("Resource/images/Enemy3.png");
}

void Enemy::Update(GameMainScene* gamemainscene)
{
	count++;

	if (count >= 1000) count = 0;
	if (count % 50 == 0 && count < 500)
	{
		float ShootAngleX = playerx - location.x;
		float ShootAngleY = playery - location.y;
		Normalize = atan2(ShootAngleX, ShootAngleY) * 180.0f / DX_PI;
		BulletShoot(gamemainscene,90 - Normalize,tag);
	}
	if (backflg == 0) {//最初の位置へ戻るときはY軸の移動はしない

		if (count < 500) {
			//仮　縦に反射
			location.y += Yspeed;
			if (location.y < 20) {
				Yspeed *= -1;
			}
			else if (location.y > 480-box_size.y) {
				Yspeed *= -1;
			}
		}
	}
	//プレイヤーに向かってまっすぐ進む
		if (count >= 500) {
			attackflg = 1;
			if (PX + 15 < location.x && backflg == 0) {
				location.x = location.x - 1;
			}
			if (PX + 15 > location.x && backflg == 0) {
				location.x = location.x + 1;
			}

			if (PY < location.y && backflg == 0) {
				location.y = location.y - 1;

			}
			if (PY > location.y && backflg == 0) {
				location.y = location.y + 1;

			}
		}

	//プレイヤーの元いた場所まで来たら戻る
	
	

	//敵を元の位置に戻す
	if (PX  + 15 == location.x ) {
		backflg = 1;
	}
	
	if (backflg == 1 && location.x < 600) {
		location.x = location.x + 10;
		attackflg = 0;
	}
	
	if (backflg == 1 && location.x >= 600) {
		backflg = 0;
		count = 0;
	}

	if (attackflg == 0) {
		PX = playerx;
		PY = playery;
	}

	if (hit <= 10) {
		hp = hpber - hit;
	}
	//HPが0になったらの処理↓
	if (hp < 0) {
		hpflg = 1;
		hit = 0;
	}
	
	if (hitflg == 1 ) {
		Ecount++;
		if (Ecount >= 100) {
			hitflg = 0;
			Ecount = 0;
		}
	}
}

void Enemy::Draw()const
{

	//仮・敵 攻撃を受けたら　普通の顔->笑ってる顔とかに変えたい
	DrawRotaGraph(location.x, location.y, 0.1,0,enemy_img,TRUE);

	if (hitflg == 1) {
		SetFontSize(20);
		if (hp > 0) {
			DrawFormatString(580, 0, 0xffffff, "HP %d", hp);
		}
		if (hp == 0) {
			DrawFormatString(520, 0, 0xffffff, "笑い死んだ！");
		}
	}
}

void Enemy::Finalize()
{
}

void Enemy::SetEnemy(int x,int y)
{
	hit = x;
	hitflg = y;
}



Vector2D Enemy::GetBoxSize() const
{
	return this->box_size;
}

char Enemy::GetTag() const
{
	return this->tag;
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

void Enemy::BulletShoot(GameMainScene* gamemainscene, float _angle, char _tag)
{
	gamemainscene->SpawnBullet(location + (box_size / 2), _angle, _tag);
}