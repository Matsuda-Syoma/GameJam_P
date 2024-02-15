#include "HelpScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"


HelpScene::HelpScene() : background_image(NULL),text_image(NULL)
{
}

HelpScene::~HelpScene()
{
}

void HelpScene::Initialize()
{
    // �摜�̓ǂݍ���
    background_image = LoadGraph("Resource/images/Title.jpg");
    text_image = LoadGraph("Resource/images/Help.png");
    setumei_image = LoadGraph("Resource/images/setumei.png");

    // �G���[�`�F�b�N
    if (background_image == -1)
    {
        throw("Resource/images/Title.jpg������܂���\n");
    }
    if (text_image == -1)
    {
        throw("Resource/images/Help.png������܂���\n");
    }
    if (setumei_image == -1)
    {
        throw("Resource/images/setumei.png������܂���\n");
    }
}

// ������
eSceneType HelpScene::Update()
{
    // A�{�^���������ꂽ��A�^�C�g���ɖ߂�
    if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
    {
        return eSceneType::E_TITLE;
    }
    return GetNowScene();
}

// �`��
void HelpScene::Draw() const
{
    // �w�i�̕`��
    DrawGraph(0, 0, background_image, FALSE);
    DrawGraph(0, 0, text_image, FALSE);
    DrawGraph(130, 110, setumei_image, FALSE);

    //�^�C�g���֖߂镶��
    DrawString(200, 450, "�^�C�g���֖߂�    A�{�^��", GetColor(0,0,0));
}

// �I��������
void HelpScene::Finalize()
{
    // �ǂݍ��񂾉摜���폜
    DeleteGraph(background_image);
    DeleteGraph(text_image);
    DeleteGraph(setumei_image);
}

// ���݂̃V�[��
eSceneType HelpScene::GetNowScene() const
{
    return eSceneType::E_HELP;
}
