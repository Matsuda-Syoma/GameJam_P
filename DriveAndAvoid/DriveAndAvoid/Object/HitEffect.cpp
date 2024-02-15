#include "HitEffect.h"
#include "DxLib.h"
HitEffect::HitEffect() : location(0.0f), image{ 0 }, is_active(false), random(0),velocity(0.0f)
{
}

HitEffect::~HitEffect()
{
}

void HitEffect::Initialize(Vector2D loc)
{
	location.x = loc.x;
	location.y = loc.y;

	is_active = true;

	velocity = Vector2D((float)GetRand(5) - 2, (float)GetRand(4) - 4);
	random = GetRand(4);
	//画像の読み込み
	int result = LoadDivGraph("Resource/images/hiteffect.bmp", 4, 4, 1, 64, 32, image);

	//エラーチェック
	if (result == -1)
	{
		throw("Resource/images/hiteffect.bmpがありません。\n");
	}
}

Vector2D HitEffect::GetLocation() const
{
	return this->location;
}

void HitEffect::Update()
{
	location += velocity;
	i++;
	if (i > 32) {
		is_active = false;
	}
}

void HitEffect::Draw() const
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - i * 8);
	DrawExtendGraphF(location.x - (2 * i), location.y - (1 * i), (location.x + 64) + (2 * i), (location.y + 32) + (1 * i), image[random], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//DrawRotaGraphF(location.x, location.y, 1.0 + (i/100), 0.0, image[1], TRUE);
}

bool HitEffect::GetActive() const
{
	return this->is_active;
}
