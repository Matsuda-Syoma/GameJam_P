#pragma once

#include "../Utility/Vector2D.h"
#include "BoxCollider.h"
#include "Player.h"
class GameMainScene;
class Enemy : public  BoxCollider
{
private:


	Vector2D location;		// 位置座標
	Vector2D box_size;		// 当たり判定の大きさ
	char tag;				// タグ

	int Xposition; //X座標
	int Yposition; //Y座標

	int Xspeed; //X軸・移動速度
	int Yspeed; //Y軸・移動族度
	int hp; //仮HP
	int radius; // 半径
	int backflg = 0;
	int enemy_img;

	float playerx;
	float playery;
	float PX;
	float PY;
	int attackflg = 0;
	float Normalize = 0;

	Player* player;


	void BulletShoot(GameMainScene* gamemainscene, float _angle, char _tag);
public:
	Enemy();
	~Enemy();

	int count = 0;


	void SetLocation(float x, float y);		// Locationの指定

	Vector2D GetLocation() const;			// 位置情報取得
	Vector2D GetBoxSize() const;			// 当たり判定のおおきさ取得
	char GetTag() const;					// Tag取得

	void Initialize();			// 初期化処理
	void Update(GameMainScene* gamemainscene);	// 更新処理
	void Draw() const;			// 描画処理
	void Finalize();			// 終了時処理


};