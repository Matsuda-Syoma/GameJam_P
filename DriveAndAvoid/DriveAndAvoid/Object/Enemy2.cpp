#include "Enemy2.h"
#include"DxLib.h"
Enemy::Enemy():location(0.0f), box_size(0.0f)
{

}

Enemy::~Enemy()
{

}

// ����������
void Enemy::Initialize()
{
	location = Vector2D(320.0f, 80.0f);
	box_size = Vector2D(32.0f, 32.0f);
	tag = 'e2';

	radius = 20;//���a
	hp = 20;//�GHP

	Xspeed = 10;
	Yspeed = 10;
	count = 0;

	enemy_img = LoadGraph("Resource/images/Enemy1.png");
}

void Enemy::Update(GameMainScene* gamemain)
{
	// �d�͏���
	if (!is_ground)
	{
		AddVelocity();
	}

	// �������x�̐���
	if (velocity.y > 4)
	{
		velocity.y = 4;
	}
}

void Enemy::Draw()const
{
	//���E�G
//	DrawCircle(location.x, location.y,radius, 0xff0000, 1); 
	DrawRotaGraph(location.x, location.y, 0.25,0,enemy_img,TRUE);
	//�G��HP�o�[
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



//�ʒu���擾����
Vector2D Enemy::GetLocation() const
{
	return this->location;
}
