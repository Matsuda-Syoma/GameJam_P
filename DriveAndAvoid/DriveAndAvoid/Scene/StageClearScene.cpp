#include "StageClearScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"


StageClearScene::StageClearScene() : background_image(NULL)
{

}

StageClearScene::~StageClearScene()
{

}

void StageClearScene::Initialize()
{
	// �摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/StageClear.jpg");

	// �G���[�`�F�b�N
	if (background_image == -1)
	{
		throw ("Resource/images/StageClear.jpg������܂���\n");
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

}

// �I��������
void StageClearScene::Finalize()
{
	// �ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);

}

// ���݂̃V�[�������擾
eSceneType StageClearScene::GetNowScene() const
{
	return eSceneType::E_STAGECLEAR;
}
