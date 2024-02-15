#include "TitleScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

TitleScene::TitleScene() : background_image(NULL), menu_image(NULL),
cursor_image(NULL), menu_cursor(0)
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Initialize()
{
	// �摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/Title.jpg");
	menu_image = LoadGraph("Resource/images/menu.png");
	cursor_image = LoadGraph("Resource/images/bullet.bmp");

	// �G���[�`�F�b�N
	if (background_image == -1)
	{
		throw ("Resource/images/Title.jpg������܂���\n");
	}
	if (menu_image == -1)
	{
		throw ("Resource/images/menu.png������܂���\n");
	}
	if (cursor_image == -1)
	{
		throw ("Resource/images/bullet.bmp������܂���\n");
	}
}

// �X�V����
eSceneType TitleScene::Update()
{
	// �J�[�\�����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;
		// ��ԉ��ɓ��B������A��ԏ�ɂ���
		if (menu_cursor > 3)
		{
			menu_cursor = 0;
		}
	}

	// �J�[�\����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		menu_cursor--;
		// ��ԏ�ɓ��B������A��ԉ��ɂ���
		if (menu_cursor < 0)
		{
			menu_cursor = 3;
		}
	}



	// �J�[�\������
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		switch (menu_cursor)
		{
		case 0:
			return eSceneType::E_MAIN;
		case 1:
			return eSceneType::E_RANKING_DISP;
		case 2:
			return eSceneType::E_HELP;
		default:
			return eSceneType::E_END;
		}
	}
	return GetNowScene();
}

// �`�揈��
void TitleScene::Draw() const
{
	// �^�C�g���摜�̕`��
	DrawGraph(0, 0, background_image, FALSE);

	// ���j���[�摜�̕`��
	DrawGraph(215, 320, menu_image, FALSE);

	// �J�[�\���摜�̕`��
	DrawRotaGraph(185, 340 + menu_cursor * 32, 1.6, DX_PI / 200.0, cursor_image, TRUE);

}

// �I��������
void TitleScene::Finalize()
{
	// �ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(cursor_image);
}

// ���݂̃V�[�������擾
eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}