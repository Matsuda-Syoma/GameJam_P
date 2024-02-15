#include "Enemy2.h"
#include"DxLib.h"
#include "../Utility/InputControl.h"

Enemy2::Enemy2()
{

}

Enemy2::~Enemy2()
{

}

// 処理化処理
void Enemy2::Initialize()
{
	location = Vector2D(600.0f, 80.0f);
	box_size = Vector2D(32.0f, 32.0f);
	tag = 'e2';

	radius = 20;//半径
	hp = 20;//敵HP
	hpber = 10;

	Xspeed = 1;
	count = 0;

	enemy_img = LoadGraph("Resource/images/Enemy2.png");

	Angle = 0;
}

void Enemy2::Update(GameMainScene* gamemain)
{
	//移動
	location.x = location.x - Xspeed;
	if (location.x <= 0 ) {
		location.x = 600;
		location.y = 80;
	}

	// 重力処理
	if (!is_ground)
	{
		AddVelocity();
	}

	// 落下速度の制限
	if (velocity.y > 4)
	{
		velocity.y = 4;
	}
	
	if (hit <= 10) {
		hp = hpber - hit;
	}
	//HPが0になったらの処理↓
	if (hp < 0) {
		hpflg = 1;
		hit = 0;
	}

	if (hitflg == 1) {
		Ecount++;
		if (Ecount >= 100) {
			hitflg = 0;
			Ecount = 0;
		}
	}

}

void Enemy2::Draw()const
{
	//仮・敵　	//仮・敵 攻撃を受けたら　普通の顔->笑ってる顔とかに変えたい
	DrawRotaGraph(location.x, location.y, 0.1,Angle,enemy_img,TRUE);
	//DrawFormatString(location.x, location.y, 0xff0000, "(^o^)");
	
	//敵のHPバー


	if (hitflg == 1) {
		SetFontSize(20);
		if (hp > 0) {
			DrawFormatString(580, 30, 0xffffff, "HP %d", hp);
		}
		if (hp == 0) {
			DrawFormatString(520, 30, 0xffffff, "笑い死んだ！");
		}
	}

}



void Enemy2::SetLocation(float x, float y)
{
	playerx = x;
	playery = y;
}


void Enemy2::AddVelocity()
{
	Vector2D g = Vector2D(0.0f, +0.28f);
	velocity += g;
	location += velocity;
}


void Enemy2::SetGround(bool flg)
{
	this->is_ground = flg;
}

void Enemy2::SetEnemy(int x, int y)
{
	hit = x;
	hitflg = y;
}


bool Enemy2::GetGround() const
{
	return is_ground;
}


//位置情報取得処理
Vector2D Enemy2::GetLocation() const
{
	return this->location;
}

Vector2D Enemy2::GetVelocity() const
{
	return this->velocity;
}

int Enemy2::GetEnemy()
{
	return hp;
}

void Enemy2::SetVelocity(float x, float y)
{
}

//当たり判定の大きさの取得処理
Vector2D Enemy2::GetBoxSize() const
{
	return this->box_size;
}

char Enemy2::GetTag() const
{
	return this->tag;
}