#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>
GameMainScene::GameMainScene() :high_score(0), background_image(NULL), mileage(0), player(nullptr),
enemy() {



}

GameMainScene::~GameMainScene()
{
}

void GameMainScene::Initialize()
{
	// �ō��_��ǂݍ���
	ReadHighScore();

	// �摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/back.bmp");
	int result = LoadDivGraph("Resource/images/car.bmp", 3, 3, 1, 63, 120, enemy_image);
	// �G���[�`�F�b�N
	if (background_image == -1) {
		throw("�摜back.bmp������܂���\n");
	}
	if (result == -1) {
		throw("�摜car.bmp������܂���\n");
	}

	// �I�u�W�F�N�g�̐���
	player = new Player;

	// �I�u�W�F�N�g�̏�����
	player->Initialize();

	enemy = new Enemy;

	enemy->Initialize();

}

eSceneType GameMainScene::Update()
{
	//// �v���C���[�̍X�V
	//player->Update();
	enemy->Update();

	return GetNowScene();
}

void GameMainScene::Draw() const
{
	//// �w�i�摜�̕`��
	//DrawGraph(0, mileage % 480 - 480, background_image, TRUE);
	//DrawGraph(0, mileage % 480, background_image, TRUE);



	//// �v���C���[�̕`��
	//player->Draw();

	enemy->Draw();
}

void GameMainScene::Finalize()
{

}

// ���݂̃V�[�����擾
eSceneType GameMainScene::GetNowScene() const
{
	return eSceneType::E_MAIN;
}

// �n�C�X�R�A�Ǎ�
void GameMainScene::ReadHighScore()
{
}

// �����蔻�菈���i�v���C���[�ƓG�j
bool GameMainScene::IsHitCheck(Player* p, Enemy* e)
{

	// �G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (e == nullptr) {
		return false;
	}

	
}
