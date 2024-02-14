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

// ˆ—‰»ˆ—
void Enemy::Initialize()
{
	location = Vector2D(320.0f, 80.0f);
	box_size = Vector2D(64.0f, 32.0f);

	radius = 20;//”¼Œa
	hp = 20;//“GHP

	tag = 'e';

	Xspeed = 10;
	Yspeed = 10;
	count = 0;

	enemy_img = LoadGraph("Resource/images/Enemy1.png");
}

void Enemy::Update(GameMainScene* gamemainscene)
{
	count++;

	if (count >= 1000) count = 0;
	if (count % 100 == 0 && count < 500)
	{
		float ShootAngleX = playerx - location.x;
		float ShootAngleY = playery - location.y;
		Normalize = atan2(ShootAngleX, ShootAngleY) * 180.0f / DX_PI;
		BulletShoot(gamemainscene,90 - Normalize,tag);
	}
	if (backflg == 0) {//Å‰‚ÌˆÊ’u‚Ö–ß‚é‚Æ‚«‚ÍYŽ²‚ÌˆÚ“®‚Í‚µ‚È‚¢

		if (count < 500) {
			//‰¼@c‚É”½ŽË
			location.y += Yspeed;
			if (location.y < 20) {
				Yspeed *= -1;
			}
			else if (location.y > 480-box_size.y) {
				Yspeed *= -1;
			}
		}
	}
	//ƒvƒŒƒCƒ„[‚ÉŒü‚©‚Á‚Ä‚Ü‚Á‚·‚®i‚Þ
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

	//“G‚ðŒ³‚ÌˆÊ’u‚É–ß‚·
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
	//‰¼E“G
//	DrawCircle(location.x, location.y,radius, 0xff0000, 1); 
	DrawRotaGraph(location.x + box_size.x / 2, location.y + box_size.y / 2, 0.25,0,enemy_img,TRUE);
	DrawBox(location.x, location.y, location.x + box_size.x, location.y + box_size.y, 0xffffff, false);
	//“G‚ÌHPƒo[
	DrawBox(location.x - hp, location.y - 30, location.x  + hp, location.y -25, 0xfff000, TRUE);

}

void Enemy::Finalize()
{
}

Vector2D Enemy::GetBoxSize() const
{
	return Vector2D();
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



//ˆÊ’uî•ñŽæ“¾ˆ—
Vector2D Enemy::GetLocation() const
{
	return this->location;
}

void Enemy::BulletShoot(GameMainScene* gamemainscene, float _angle, char _tag)
{
	gamemainscene->SpawnBullet(location + (box_size / 2), _angle, _tag);
}