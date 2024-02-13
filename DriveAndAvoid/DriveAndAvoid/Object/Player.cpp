#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

Player::Player() : is_active(false), is_ground(false), image(NULL), location(0.0f), box_size(0.0f),
velocity(0.0f), angle(0.0f), speed(0.0f), hp(0.0f)
{

}
Player::~Player()
{

}

//����������
void Player::Initialize()
{
	is_active = true;
	location = Vector2D(320.0f, 80.0f);
	box_size = Vector2D(32.0f, 32.0f);
	angle = 0.0f;
	speed = 3.0f;
	hp = 100;

	//�摜�̓ǂݍ���
	image = LoadGraph("Resource/images/car1pol.bmp");

	//�G���[�`�F�b�N
	if (image == -1)
	{
		throw("Resource/images/car1pol.bmp������܂���B\n");
	}
}

//�X�V����
void Player::Update()
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

	//�ړ�����
	Movement();

	//��������
	Acceleration();

	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		is_active = false;
	}
}

//�`�揈��
void Player::Draw()
{
	//�v���C���[�摜�̕`��
	DrawBox(location.x, location.y, location.x + box_size.x, location.y + box_size.y, 0xffffff, true);
	//DrawRotaGraphF(location.x, location.y, 1.0f, angle, image, TRUE);

}

//�I������
void Player::Finalize()
{
	//�ǂݍ��񂾉摜���폜
	DeleteGraph(image);

}

//��Ԑݒ菈��
void Player::SetActive(bool flg)
{
	this->is_active = flg;
}

void Player::SetGround(bool flg)
{
	this->is_ground = flg;
}

void Player::SetLocation(float x, float y)
{
	this->location = Vector2D(x, y);
}

// Velocity�̐ݒ�
void Player::SetVelocity(float x, float y)
{
	this->velocity = Vector2D(x,y);
}

//�̗͌�������
void Player::DecreaseHp(float value)
{
	this->hp += value;
}

bool Player::GetGround() const
{
	return is_ground;
}

//�ʒu���擾����
Vector2D Player::GetLocation() const
{
	return this->location;
}

Vector2D Player::GetVelocity() const
{
	return this->velocity;
}

//�����蔻��̑傫���̎擾����
Vector2D Player::GetBoxSize() const
{
	return this->box_size;
}
//�����擾����
float Player::GetSpeed() const
{
	return this->speed;
}
//�̗͎擾����
float Player::GetHp() const
{
	return this->hp;
}

void Player::AddVelocity()
{
	Vector2D g = Vector2D(0.0f, +0.28f);
	velocity += g;
	location += velocity;
}

//�ړ�����
void Player::Movement()
{
	Vector2D move = Vector2D(0.0f);

	//�\���ړ�����
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_LEFT) || InputControl::GetLeftStick().x  < -0.8)
	{
		move += Vector2D(-1.0f * speed, 0.0f);
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_RIGHT) || InputControl::GetLeftStick().x > 0.8)
	{
		move += Vector2D(1.0f * speed, 0.0f);
	}
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		if (is_ground)
		{
			location += Vector2D(0.0f, -4.0f);
			velocity += Vector2D(0.0f, -7.5f);
		}

	}
	location += move;
}

//����������
void Player::Acceleration()
{
	//LB�{�^���������ꂽ��A��������
	if (InputControl::GetButtonDown(XINPUT_BUTTON_LEFT_SHOULDER) && speed > 1.0f)
	{
		speed -= 1.0f;
	}
	//RB�{�^���������ꂽ��A��������
	if (InputControl::GetButtonDown(XINPUT_BUTTON_RIGHT_SHOULDER) && speed < 10.0f)
	{
		speed += 1.0f;
	}
}