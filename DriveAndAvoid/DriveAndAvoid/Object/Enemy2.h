#pragma once

#include "../Utility/Vector2D.h"
#include "BoxCollider.h"
#include "Player.h"
class Enemy2 : public  BoxCollider
{
private:
	Vector2D velocity;		// 重力
	char tag;				// タグ

	bool is_ground;			// 地面にいるか


	int Xposition; //X座標
	int Yposition; //Y座標

	int Xspeed; //X軸・移動速度
	int Yspeed; //Y軸・移動族度
	int hp; //仮HP
	int radius; // 半径
	int enemy_img;

	float playerx;
	float playery;
	float PX;
	float PY;
	int attackflg = 0;
	int hit;
	int hpflg = 0;
	int hpber;

	Player* player;
public:
	Enemy2();
	~Enemy2();

	int count = 0;


	void SetLocation(float x, float y);		// Locationの指定
	
	Vector2D GetLocation() const;			// 位置情報取得
	Vector2D GetBoxSize() const;			// 当たり判定のおおきさ取得
	char GetTag() const;					// Tag取得

	void Initialize();			// 初期化処理
	void Update(GameMainScene* gamemain);		// 更新処理
	void Draw() const;			// 描画処理

	void AddVelocity();					// 重力処理
	void SetGround(bool flg);				// 地面にいるか設定
	bool GetGround() const;				// 体力減少処理
	Vector2D GetVelocity() const;			// velocity情報取得
	void SetVelocity(float x, float y);		// Velocityの指定
	void Setcount(int  x);		


};