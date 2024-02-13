#pragma once

#include "SceneBase.h"
#include "../Object/Player.h"
#include "../Object/Enemy.h"
#include "../Object/Block.h"
class GameMainScene : public SceneBase
{
private:
	int score;              //�X�R�A
	int high_score;			// �n�C�X�R�A
	int background_image;	// �w�i�摜
	int mileage;			// ���s����
	int enemy_count[3];		// �ʂ�߂����G�J�E���g
	int enemy_image[3];		// �G�摜
	Player* player;			// �v���C���[
	Enemy** enemy;			// �G
	Block** block;			// �u���b�N

public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	virtual eSceneType GetNowScene() const override;

private:
	// �n�C�X�R�A�ǂݍ��ݏ���
	void ReadHighScore();
	// �����蔻��
	bool IsHitCheck(Player* p, Enemy* e);
	bool IsHitCheck(Player* p, Block* b);
};
