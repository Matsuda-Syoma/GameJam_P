#include "Player.h"
#include "../Scene/GameMainScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"
#include <math.h>
Player::Player() : is_active(false), is_reverse(false), is_ground(false), image(NULL),
velocity(0.0f), angle(0.0f), speed(0.0f), hp(0.0f),tag('\0')
{

}
Player::~Player()
{

}

//初期化処理
void Player::Initialize()
{
	is_active = true;
	location = Vector2D(32.0f, 480.0f - 64.0f);
	box_size = Vector2D(32.0f, 32.0f);
	angle = 0.0f;
	speed = 3.0f;
	hp = 100;
	tag = 'p';

	//画像の読み込み
	image = LoadGraph("Resource/images/playre.png");

	//エラーチェック
	if (image == -1)
	{
		throw("Resource/images/car1pol.bmpがありません。\n");
	}
}

//更新処理
void Player::Update(GameMainScene* gamemain)
{

	// 重力処理
		AddVelocity();


	// 落下速度の制限
	if (velocity.y > 4)
	{
		velocity.y = 4;
	}
	// 慣性の制限
	if (velocity.x > speed)
	{
		velocity.x = speed;
	}
	else if (velocity.x < -speed)
	{
		velocity.x = -speed;
	}
	if (velocity.x > 0)
	{
		velocity.x += -0.1;
	}
	else if (velocity.x < 0)
	{
		velocity.x += 0.1;
	}
	if (fabs(velocity.x) < 0.2)
	{
		velocity.x = 0;
	}

	//移動処理
	Movement();

	//加速処理
	Acceleration();

	if (ratecnt > 0)
	{
		ratecnt--;
	}

	if (InputControl::GetButton(XINPUT_BUTTON_A) && ratecnt <= 0)
	{
		BulletShoot(gamemain,is_reverse * 180, tag);
		ratecnt = rate;
	}

	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		is_active = false;
	}

	if (location.x < 0)
	{
		location.x = 0;
	}
	if (location.x >= 640.0f - box_size.x)
	{
		location.x = 640.0f - box_size.x;
	}
}

//描画処理
void Player::Draw()
{
	//プレイヤー画像の描画
	//DrawBox(location.x, location.y, location.x + box_size.x, location.y + box_size.y, 0xffffff, true);
	if (PlayreFlg == 2) {
		DrawGraph(location.x, location.y - 30, image, TRUE);
	}
	else {
		DrawTurnGraph(location.x, location.y - 30,image,TRUE);
	}
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

char Player::GetTag() const
{
	return this->tag;
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

	if (InputControl::GetLeftStick().x > -0.8 || InputControl::GetLeftStick().x < 0.8)
	{

	}
	//十字移動処理
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_LEFT) || InputControl::GetLeftStick().x  < -0.8)
	{
		is_reverse = true;
		velocity += Vector2D(-0.5f,0.0f);
		PlayreFlg = 1;
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_RIGHT) || InputControl::GetLeftStick().x > 0.8)
	{
		is_reverse = false;
		velocity += Vector2D(0.5f, 0.0f);
		PlayreFlg = 2;
	}


	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		if (is_ground)
		{
			location += Vector2D(0.0f, -4.0f);
			velocity += Vector2D(0.0f, -9.5f);
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

void Player::BulletShoot(GameMainScene* gamemainscene, float _angle, char _tag)
{
	gamemainscene->SpawnBullet(location + (box_size / 2), _angle, _tag);
}
