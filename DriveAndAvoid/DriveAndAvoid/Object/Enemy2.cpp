#include "Enemy2.h"
#include"DxLib.h"
#include "../Utility/InputControl.h"

Enemy2::Enemy2() : tag('\0')
{

}

Enemy2::~Enemy2()
{

}

// ����������
void Enemy2::Initialize()
{
	location = Vector2D(500.0f, 80.0f);
	box_size = Vector2D(32.0f, 32.0f);
	tag = 'e';

	radius = 20;//���a
	hp = 20;//�GHP
	hpber = 10;

	Xspeed = 10;
	Yspeed = 10;
	count = 0;

	enemy_img = LoadGraph("Resource/images/Enemy2.png");
}

void Enemy2::Update(GameMainScene* gamemain)
{
	//�ړ�
	location.x--;

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

	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_LEFT) || InputControl::GetLeftStick().x < -0.8)
	{
	if (is_ground)
	{
		location.x = location.x - 1;
	}
	}

	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_RIGHT) || InputControl::GetLeftStick().x < -0.8)
	{
		if (is_ground)
		{
			location.x = location.x + 1;
		}
	}
	if (hit <= 10) {
		hp = hpber - hit;
	}
	//HP��0�ɂȂ�����̏�����
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
	//���E�G�@	//���E�G �U�����󂯂���@���ʂ̊�->�΂��Ă��Ƃ��ɕς�����
	DrawRotaGraph(location.x, location.y, 0.1,0,enemy_img,TRUE);
	//DrawFormatString(location.x, location.y, 0xff0000, "(^o^)");
	
	//�G��HP�o�[


	if (hitflg == 1) {
		SetFontSize(20);
		if (hp > 0) {
			DrawFormatString(580, 30, 0xffffff, "HP %d", hp);
		}
		if (hp == 0) {
			DrawFormatString(520, 30, 0xffffff, "�΂����񂾁I");
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


//�ʒu���擾����
Vector2D Enemy2::GetLocation() const
{
	return this->location;
}

Vector2D Enemy2::GetVelocity() const
{
	return this->velocity;
}

void Enemy2::SetVelocity(float x, float y)
{
}

//�����蔻��̑傫���̎擾����
Vector2D Enemy2::GetBoxSize() const
{
	return this->box_size;
}

char Enemy2::GetTag() const
{
	return this->tag;
}