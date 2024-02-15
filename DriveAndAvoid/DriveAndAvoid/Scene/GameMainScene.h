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
	int score;              //スコア
	int high_score;			// ハイスコア
	int background_image;	// 背景画像
	int mileage;			// 走行距離
	int enemy_count[3];		// 通り過ぎた敵カウント
	int enemy_image[3];		// 敵画像
	int bullet_num;			//弾・添字
	Player* player;			// プレイヤー
	Enemy** enemy;			// 敵
	Enemy2** enemy2;			//敵2
	Block** block;			// ブロック
	Bullet** bullet;		//弾
	HitEffect** hiteffect;		//弾

	int hit = 0;				//hitカウント
	int hit2 = 0;			//hit2カウント
	int enemyflg = 0;

	int Ehp;				//敵1のHP
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
	// ハイスコア読み込み処理
	void ReadHighScore();
	// 当たり判定
	bool IsHitCheck(BoxCollider* p, BoxCollider* e);
	bool IsGroundCheck(Player* p, Block* b);
	bool IsGroundCheck(Enemy2* p, Block* b);

	int IsHitCheck(Player* p, Block* b);
	int IsHitCheck(Enemy* e, Block* b);

};

