#pragma once

#include "SceneBase.h"
#include "../Object/Player.h"
#include "../Object/Enemy.h"
#include "../Object/Enemy2.h"
#include "../Object/Block.h"
#include "../Object/Bullet.h"
#include "../Object/HitEffect.h"

#include "ResultScene.h"

#include "../Utility/LoadStage.h"
class GameMainScene : public SceneBase
{
private:
	int score;              //�X�R�A
	int high_score;			// �n�C�X�R�A
	int background_image;	// �w�i�摜
	int mileage;			// ���s����
	int enemy_count[3];		// �ʂ�߂����G�J�E���g
	int enemy_image[3];		// �G�摜
	int bullet_num;			//�e�E�Y��
	Player* player;			// �v���C���[
	Enemy** enemy;			// �G
	Enemy2** enemy2;			//�G2
	Block** block;			// �u���b�N
	Bullet** bullet;		//�e
	HitEffect** hiteffect;		//�e

	int hit = 0;				//hit�J�E���g
	int hit2 = 0;			//hit2�J�E���g
	int enemyflg = 0;

	int Ehp;				//�G1��HP
	int Escore = 0;
public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	virtual eSceneType GetNowScene() const override;

	Player* GetPlayer();
	void SpawnBullet(Vector2D loc, float _angle, char _name);

	void SpawnHitEffect(Vector2D loc);


	int  EnemyScore();
private:
	// �n�C�X�R�A�ǂݍ��ݏ���
	void ReadHighScore();
	// �����蔻��
	bool IsHitCheck(BoxCollider* p, BoxCollider* e);
	bool IsGroundCheck(Player* p, Block* b);
	bool IsGroundCheck(Enemy2* p, Block* b);

	int IsHitCheck(Player* p, Block* b);
	int IsHitCheck(Enemy* e, Block* b);

};

