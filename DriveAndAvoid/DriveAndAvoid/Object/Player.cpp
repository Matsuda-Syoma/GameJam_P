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

//初期化処理
void Player::Initialize()
{
	is_active = true;
	location = Vector2D(320.0f, 80.0f);
	box_size = Vector2D(32.0f, 32.0f);
	angle = 0.0f;
	speed = 3.0f;
	hp = 100;

	//画像の読み込み
	image = LoadGraph("Resource/images/car1pol.bmp");

	//エラーチェック
	if (image == -1)
	{
		throw("Resource/images/car1pol.bmpがありません。\n");
	}
}

//更新処理
void Player::Update()
{

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

	//移動処理
	Movement();

	//加速処理
	Acceleration();

	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		is_active = false;
	}
}

//描画処理
void Player::Draw()
{
	//プレイヤー画像の描画
	DrawBox(location.x, location.y, location.x + box_size.x, location.y + box_size.y, 0xffffff, true);
	//DrawRotaGraphF(location.x, location.y, 1.0f, angle, image, TRUE);

}

//終了処理
void Player::Finalize()
{
	//読み込んだ画像を削除
	DeleteGraph(image);

}

//状態設定処理
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

// Velocityの設定
void Player::SetVelocity(float x, float y)
{
	this->velocity = Vector2D(x,y);
}

//体力減少処理
void Player::DecreaseHp(float value)
{
	this->hp += value;
}

bool Player::GetGround() const
{
	return is_ground;
}

//位置情報取得処理
Vector2D Player::GetLocation() const
{
	return this->location;
}

Vector2D Player::GetVelocity() const
{
	return this->velocity;
}

//当たり判定の大きさの取得処理
Vector2D Player::GetBoxSize() const
{
	return this->box_size;
}
//速さ取得処理
float Player::GetSpeed() const
{
	return this->speed;
}
//体力取得処理
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

//移動処理
void Player::Movement()
{
	Vector2D move = Vector2D(0.0f);

	//十字移動処理
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

//加減速処理
void Player::Acceleration()
{
	//LBボタンが押されたら、減速する
	if (InputControl::GetButtonDown(XINPUT_BUTTON_LEFT_SHOULDER) && speed > 1.0f)
	{
		speed -= 1.0f;
	}
	//RBボタンが押されたら、加速する
	if (InputControl::GetButtonDown(XINPUT_BUTTON_RIGHT_SHOULDER) && speed < 10.0f)
	{
		speed += 1.0f;
	}
}