#include "StageClearScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"


StageClearScene::StageClearScene() : background_image(NULL),text_image(NULL),mob_image(NULL)
{

}

StageClearScene::~StageClearScene()
{

}

void StageClearScene::Initialize()
{
	// �摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/StageClearScene.png");
	text_image = LoadGraph("Resource/images/StageClear.png");
	mob_image = LoadGraph("Resource/images/mob.bmp");

	// �G���[�`�F�b�N
	if (background_image == -1)
	{
		throw ("Resource/images/StageClearScene.png������܂���\n");
	}
	if (text_image == -1)
	{
		throw("Resource/images/StageClear.png������܂���\n");
	}
	if (mob_image == -1)
	{
		throw("Resource/images/mob.bmp������܂���\n");
	}
}

// �X�V����
eSceneType StageClearScene::Update()
{
	//A�{�^���Ŏ��̃X�e�[�W�ɑJ�ڂ���
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		return eSceneType::E_MAIN;
	}

	return GetNowScene();
}

// �`�揈��
void StageClearScene::Draw() const
{
	//�X�e�[�W�N���A�摜�̕`��
	DrawGraph(0, 0, background_image, FALSE);
	//�X�e�[�W�N���A�e�L�X�g�摜�̕`��
	DrawGraph(5, 45, text_image, FALSE);
	//�X�e�[�W�N���A��ʎ��̃L�����N�^�[�`��
	DrawGraph(290, 250, mob_image, FALSE);

	//���̃V�[���֐؂�ւ�
	DrawString(200, 430, "���̃X�e�[�W    A�{�^��", 0xffffff);
}

// �I��������
void StageClearScene::Finalize()
{
	// �ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);
	DeleteGraph(text_image);
	DeleteGraph(mob_image);
}

// ���݂̃V�[�������擾
eSceneType StageClearScene::GetNowScene() const
{
	return eSceneType::E_STAGECLEAR;
}
