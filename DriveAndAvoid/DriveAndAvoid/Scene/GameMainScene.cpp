#include "GameMainScene.h"
#include "Dxlib.h"
#include <math.h>

#include "../Utility/InputControl.h"
GameMainScene::GameMainScene() :score(0), high_score(0), background_image(NULL), mileage(0), player(nullptr),
enemy(nullptr),block(nullptr) {


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

		enemy[0] = new Enemy();
	enemy[0]->Initialize();

	for (int i = 0; i < 20; i++) {
		block[i] = new Block(0);
		block[i]->Initialize(i, 14);
	}
	for (int i = 0; i < 25; i++) {
		if (block[i] == nullptr) {
			block[i] = new Block(0);
			block[i]->Initialize(8, 13);
			//block[i + 1] = new Block(0);
			//block[i + 1]->Initialize(8, 12);
			//block[i + 2] = new Block(0);
			//block[i + 2]->Initialize(8, 11);
			block[i + 3] = new Block(0);
			block[i + 3]->Initialize(8, 10);
			break;
		}
	}


}

eSceneType GameMainScene::Update()
{
	// �v���C���[���n�ʂɂ��邩�`�F�b�N
	player->SetGround(false);
	for (int i = 0; i < 300; i++)
	{
		// �l��null�łȂ��Ȃ�
		if (block[i] != nullptr)
		{
			if (IsGroundCheck(player, block[i]))
			{
				player->SetVelocity(0, 0);
				player->SetGround(true);
			}
		}
	}

	// �v���C���[�̍X�V
	player->Update();

	// �u���b�N�̍X�V�Ɠ����蔻��`�F�b�N
	for (int i = 0; i < 300; i++)
	{
		// �l��null�łȂ��Ȃ�
		if (block[i] != nullptr)
		{
			// �����蔻��̊m�F
			if (int value = IsHitCheck(player, block[i]))
			{
				switch (value)
				{
					// �v���C���[�̍��̃u���b�N�ɓ��������Ƃ�
				case 1:
					player->SetLocation(block[i]->GetLocation().x + block[i]->GetBoxSize().x, player->GetLocation().y);
					break;
					// �v���C���[�̏�̃u���b�N�ɓ��������Ƃ�
				case 2:
					player->SetVelocity(player->GetVelocity().x, player->GetVelocity().y / 2);
					player->SetLocation(player->GetLocation().x, block[i]->GetLocation().y + block[i]->GetBoxSize().y);
					break;
					// �v���C���[�̉E�̃u���b�N�ɓ��������Ƃ�
				case 3:
					player->SetLocation(block[i]->GetLocation().x - block[i]->GetBoxSize().x, player->GetLocation().y);
					break;
					// �v���C���[�̉��̃u���b�N�ɓ��������Ƃ�
				case 4:
					player->SetLocation(player->GetLocation().x, block[i]->GetLocation().y - block[i]->GetBoxSize().y);
					break;
				}
			}
		}
	}

	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		return E_RESULT;
	}

	if (enemy[0] != nullptr)
	{
		//�G�l�~�[�̍X�V
		enemy[0]->Update();
	}

	//syun Enemy�Ƀv���C���[�̍��W�����Ă�����
	enemy[0]->SetLocation(player->GetLocation().x, player->GetLocation().y);

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

	if (enemy[0] != nullptr)
	{
		//�G�l�~�[�̕`��
		enemy[0]->Draw();
	}

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
int GameMainScene::IsHitCheck(Player* p, Block* b)
{

	// �G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (b == nullptr) {
		return 0;
	}

	// �ʒu���̍����擾
	Vector2D diff_location = p->GetLocation() - b->GetLocation();
	// �����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + b->GetBoxSize();
	// �������Ă���Ȃ����
	if ((fabs(diff_location.x) < box_ex.x / 2) && (fabsf(diff_location.y) < box_ex.y / 2))
	{
		// �ꎞ�ۑ��p�ϐ��̍쐬
		Vector2D work_vector = 0.0f;
		Vector2D work_vector2 = 0.0f;
		Vector2D min_vector = 0.0f;
		int select[2] = { 0 };
		int finret = 0;

		// �Ώۂ̍��W�Ɠ����蔻��𑫂����ϐ��̍쐬
		// �v���C���[
		Vector2D p_location = p->GetLocation();
		Vector2D p_location2 = p->GetLocation() + p->GetBoxSize();

		// �u���b�N
		Vector2D b_location = b->GetLocation();
		Vector2D b_location2 = b->GetLocation() + b->GetBoxSize();

		// �㉺���E�̋�����ۑ�
		work_vector.x = fabsf(p_location.x - b_location2.x);
		work_vector2.x = fabsf(p_location2.x - b_location.x);
		work_vector.y = fabsf(p_location.y - b_location2.y);
		work_vector2.y = fabsf(p_location2.y - b_location.y);

		// ���̏����������������Ŋm�F�A�ۑ�
		if (work_vector.x < work_vector2.x)
		{
			min_vector.x = work_vector.x;
			select[0] = 1;
		}
		else
		{
			min_vector.x = work_vector2.x;
			select[0] = 3;
		}

		// �c�̏����������������Ŋm�F�A�ۑ�
		if (work_vector.y < work_vector2.y)
		{
			min_vector.y = work_vector.y;
			select[1] = 2;
		}
		else
		{
			min_vector.y = work_vector2.y;
			select[1] = 4;
		}

		// �c���̏����������������Ŋm�F�AReturn�ŕԂ�
		if (min_vector.x < min_vector.y)
		{
			finret = select[0];
		}
		else
		{
			finret = select[1];
		}
		return finret;
	}
	return 0;
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