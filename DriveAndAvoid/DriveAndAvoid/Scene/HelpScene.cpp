#include "HelpScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"


HelpScene::HelpScene() : background_image(NULL)
{
}

HelpScene::~HelpScene()
{
}

void HelpScene::Initialize()
{
    // �摜�̓ǂݍ���
    background_image = LoadGraph("Resource/images/Title.bmp");

    // �G���[�`�F�b�N
    if (background_image == -1) {
        throw("Resource/images/Title.bmp������܂���\n");
    }

}

// ������
eSceneType HelpScene::Update()
{
    // B�{�^���������ꂽ��A�^�C�g���ɖ߂�
    if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
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
}

// �I��������
void HelpScene::Finalize()
{
    // �ǂݍ��񂾉摜���폜
    DeleteGraph(background_image);
}

// ���݂̃V�[��
eSceneType HelpScene::GetNowScene() const
{
    return eSceneType::E_HELP;
}
