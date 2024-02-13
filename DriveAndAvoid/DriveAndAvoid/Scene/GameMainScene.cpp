#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene() :high_score(0), background_image(NULL), mileage(0), player(nullptr),
enemy(nullptr),block(nullptr) {
	for (int i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
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
	enemy = new Enemy * [10];
	block = new Block * [300];

	// �I�u�W�F�N�g�̏�����
	player->Initialize();

	for (int i = 0; i < 10; i++) {
		enemy[i] = nullptr;
	}
	for (int i = 0; i < 300; i++) {
		block[i] = nullptr;
	}

	block[0] = new Block(0);
	block[0]->Initialize(10, 8);

	//for (int i = 0; i < 20; i++) {
	//	block[i] = new Block(0);
	//	block[i]->Initialize(i, 14);
	//}
}

eSceneType GameMainScene::Update()
{
	player->SetGround(false);
	// �G�̍X�V�Ɠ����蔻��`�F�b�N
	for (int i = 0; i < 300; i++)
	{
		// �l��null�łȂ��Ȃ�
		if (block[i] != nullptr)
		{
			// �����蔻��̊m�F
			if (IsHitCheck(player, block[i]))
			{
				player->SetVelocity(0,0);
				player->SetLocation(player->GetLocation().x, block[i]->GetLocation().y - block[i]->GetBoxSize().y);
			}
			if (IsGroundCheck(player, block[i]))
			{
				player->SetGround(true);
			}
		}
	}
	// �v���C���[�̍X�V
	player->Update();

	return GetNowScene();
}

void GameMainScene::Draw() const
{
	//// �w�i�摜�̕`��
	//DrawGraph(0, mileage % 480 - 480, background_image, TRUE);
	//DrawGraph(0, mileage % 480, background_image, TRUE);

	//// �G�̕`��
	//for (int i = 0; i < 10; i++)
	//{
	//	if (enemy[i] != nullptr)
	//	{
	//		enemy[i]->Draw();
	//	}
	//}

	// �u���b�N�̕`��
	for (int i = 0; i < 300; i++)
	{
		if (block[i] != nullptr)
		{
			block[i]->Draw();
		}

	}

	//// �v���C���[�̕`��
	player->Draw();

	//UI�̕`��
	DrawBox(5,10,130,45, GetColor(0,0,153), TRUE);
	SetFontSize(16);
	DrawFormatString(285, 425, GetColor(255,255,255), "SCORE");
	DrawFormatString(272, 442, GetColor(255, 255, 255), "%08d", score);
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

	// �ʒu���̍����擾
	Vector2D diff_location = p->GetLocation() - e->GetLocation();

	// �����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + e->GetBoxSize();
	// �R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����
	return ((fabs(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

// �����蔻�菈���i�v���C���[�ƃu���b�N�j
bool GameMainScene::IsHitCheck(Player* p, Block* b)
{

	// �G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (b == nullptr) {
		return false;
	}

	// �ʒu���̍����擾
	Vector2D diff_location = p->GetLocation() - b->GetLocation();

	// �����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + b->GetBoxSize();
	// �R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����
	return ((fabs(diff_location.x) < box_ex.x / 2) && (fabsf(diff_location.y) < box_ex.y / 2));
}



// �n�ʂɂ��邩�m�F�����i�v���C���[�ƃu���b�N�j
bool GameMainScene::IsGroundCheck(Player* p, Block* b)
{

	// �G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (b == nullptr) {
		return false;
	}

	// �ʒu���̍����擾
	Vector2D diff_location = p->GetLocation() - b->GetLocation();
	diff_location += Vector2D(0.0f, 0.1f);

	// �����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + b->GetBoxSize();
	// �R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����
	return ((fabs(diff_location.x) < box_ex.x / 2) && (fabsf(diff_location.y) < box_ex.y / 2));
}