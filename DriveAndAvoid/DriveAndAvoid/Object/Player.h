#pragma once

#include "../Utility/Vector2D.h"

class Player
{
private:
	bool is_active;			// 有効状態？
	bool is_ground;			// 地面にいるか
	int image;				// 画像データ
	Vector2D location;		// 位置座標
	Vector2D box_size;		// 当たり判定の大きさ
	Vector2D velocity;		// 重力
	float angle;			// 角度
	float speed;			// 速さ
	float hp;				// 体力

public:
	Player();
	~Player();

	void Initialize();	// 初期化処理
	void Update();		// 更新処理
	void Draw();		// 描画処理
	void Finalize();	// 終了時処理

public:
	void SetActive(bool flg);				// 有効フラグ設定
	void SetGround(bool flg);				// 有効フラグ設定
	void SetVelocity(float x, float y);		// Velocityの指定

	void DecreaseHp(float value);			// 体力減少処理
	Vector2D GetLocation() const;			// 位置情報取得
	Vector2D GetBoxSize() const;			// 当たり判定のおおきさ取得
	float GetSpeed() const;					// 速さ取得
	float GetHp() const;					// 体力取得



private:
	void AddVelocity();					// 重力処理
	void Movement();				// 移動処理
	void Acceleration();			// 加速処理
};