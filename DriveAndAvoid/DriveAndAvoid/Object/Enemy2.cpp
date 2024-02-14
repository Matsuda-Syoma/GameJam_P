#include "Enemy2.h"
#include"DxLib.h"
#include "../Utility/InputControl.h"

Enemy2::Enemy2():location(0.0f), box_size(0.0f)
{

}

Enemy2::~Enemy2()
{

}

// ˆ—‰»ˆ—
void Enemy2::Initialize()
{
	location = Vector2D(500.0f, 80.0f);
	box_size = Vector2D(32.0f, 32.0f);
	tag = 'e2';

	radius = 20;//”¼Œa
	hp = 20;//“GHP

	Xspeed = 10;
	Yspeed = 10;
	count = 0;

	enemy_img = LoadGraph("Resource/images/Enemy1.png");
}

void Enemy2::Update(GameMainScene* gamemain)
{
	//ˆÚ“®
	location.x--;

	// d—Íˆ—
	if (!is_ground)
	{
		AddVelocity();
	}

	// —Ž‰º‘¬“x‚Ì§ŒÀ
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

}

void Enemy2::Draw()const
{
	//‰¼E“G
	//DrawCircle(location.x, location.y,radius, 0xff0000, 1); 
	DrawRotaGraph(location.x, location.y, 0.25,0,enemy_img,TRUE);
	//“G‚ÌHPƒo[
	DrawBox(location.x - hp, location.y - 30, location.x  + hp, location.y -25, 0xfff000, TRUE);

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

bool Enemy2::GetGround() const
{
	return is_ground;
}


//ˆÊ’uî•ñŽæ“¾ˆ—
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

//“–‚½‚è”»’è‚Ì‘å‚«‚³‚ÌŽæ“¾ˆ—
Vector2D Enemy2::GetBoxSize() const
{
	return this->box_size;
}


