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

// ����������
void Enemy::Initialize()
{

	location = Vector2D(600.0f, 80.0f);
	box_size = Vector2D(32.0f, 32.0f);

	radius = 20;//���a
	hp = 20;//�GHP


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
	if (count % 100 == 0 && count < 500)
	{
		float ShootAngleX = playerx - location.x;
		float ShootAngleY = playery - location.y;
		Normalize = atan2(ShootAngleX, ShootAngleY) * 180.0f / DX_PI;
		BulletShoot(gamemainscene,90 - Normalize,tag);
	}
	if (backflg == 0) {//�ŏ��̈ʒu�֖߂�Ƃ���Y���̈ړ��͂��Ȃ�

		if (count < 500) {
			//���@�c�ɔ���
			location.y += Yspeed;
			if (location.y < 20) {
				Yspeed *= -1;
			}
			else if (location.y > 480-box_size.y) {
				Yspeed *= -1;
			}
		}
	}
	//�v���C���[�Ɍ������Ă܂������i��
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

	//�v���C���[�̌������ꏊ�܂ŗ�����߂�
	
	

	//�G�����̈ʒu�ɖ߂�
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


	//HP��0�ɂȂ�����̏�����

}

void Enemy::Draw()const
{

	//���E�G �U�����󂯂���@���ʂ̊�->�΂��Ă��Ƃ��ɕς�����
	DrawRotaGraph(location.x, location.y, 0.1,0,enemy_img,TRUE);


	//�G��HP�o�[
	DrawBox(location.x - hp, location.y - 70, location.x  + hp, location.y -65, 0xfff000, TRUE);

	DrawFormatString(100, 100, 0xffffff, "%d", backflg);
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



//�ʒu���擾����
Vector2D Enemy::GetLocation() const
{
	return this->location;
}

void Enemy::BulletShoot(GameMainScene* gamemainscene, float _angle, char _tag)
{
	gamemainscene->SpawnBullet(location + (box_size / 2), _angle, _tag);
}