#include "ResultScene.h"
#include "../Object/RankingData.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

ResultScene::ResultScene() : background_image(NULL), score(0)
{
	for (int i = 0; i < 3; i++) {
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}

ResultScene::~ResultScene()
{
}

// ������
void ResultScene::Initialize()
{
	// �摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/back.bmp");
	int result = LoadDivGraph("Resource/images/car.bmp", 3, 3, 1, 63, 120, enemy_image);

	// �G���[�`�F�b�N
	if (background_image == -1) {
		throw("Resource/images/back.bmp������܂���\n");
	}
	if (result == -1) {
		throw("Resource/images/car.bmp������܂���\n");
	}

	// �Q�[�����ʂ̓ǂݍ���
	ReadResultData();

}

// �X�V����
eSceneType ResultScene::Update()
{
	// B�{�^���Ń����L���O�ɑJ�ڂ���
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_RANKING_INPUT;
	}

	return GetNowScene();
}

void ResultScene::Draw() const
{

	// �w�i�摜��`��
	DrawGraph(0, 0, background_image, TRUE);

	// �X�R�A���\���̈�
	DrawBox(150, 150, 490, 330, GetColor(0, 153, 0), TRUE);
	DrawBox(150, 150, 490, 330, GetColor(0, 0, 0), FALSE);
}

// �I��������
void ResultScene::Finalize()
{
	// �ǂݍ��񂾉摜���폜
	DeleteGraph(background_image);
}

eSceneType ResultScene::GetNowScene() const
{
	return eSceneType::E_RESULT;
}

void ResultScene::ReadResultData()
{
	// �t�@�C���I�[�v��
	FILE* fp = nullptr;
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "r");

	// �G���[�`�F�b�N
	if (result != 0) {
		throw("Resource/dat/result_data.csv���ǂݍ��߂܂���\n");
	}

	// ���ʂ�ǂݍ���
	fscanf_s(fp, "%6d,\n", &score);

	// ���������Ɠ��_���擾
	for (int i = 0; i < 3; i++) {
		fscanf_s(fp, "%6d\n", &enemy_count[i]);
	}
	fclose(fp);
}
