#include "HitEffect.h"
#include "DxLib.h"
HitEffect::HitEffect() : location(0.0f),image{ 0 }
{
}

HitEffect::~HitEffect()
{
}

void HitEffect::Initialize(float x, float y)
{
	location.x = x;
	location.y = y;

	//�摜�̓ǂݍ���
	int result = LoadDivGraph("Resource/images/hiteffect.bmp", 4, 4, 1, 64, 32, image);

	//�G���[�`�F�b�N
	if (result == -1)
	{
		throw("Resource/images/hiteffect.bmp������܂���B\n");
	}
}

Vector2D HitEffect::GetLocation() const
{
	return this->location;
}

void HitEffect::Update()
{
}

void HitEffect::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image[1], TRUE);
}
