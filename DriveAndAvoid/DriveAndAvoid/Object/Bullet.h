#pragma once

#include "../Utility/Vector2D.h"
#include "BoxCollider.h"
#include "Enemy.h"
class Bullet : public BoxCollider
{
private:
	bool is_active;			// 有効かどうか
	Vector2D velocity;		// 速度
	float angle;			// 弾の角度
	char tag;				// 親の名前
public:
	Bullet();
	~Bullet();

	void SetLocation(float x, float y);								// Locationの指定
	Vector2D GetLocation() const;									// 位置情報取得
	Vector2D GetVelocity() const;									// velocity情報取得
	Vector2D GetBoxSize() const;									// 当たり判定のおおきさ取得
	float GetSpeed() const;											// 速さ取得
	void Initialize(Vector2D loc, float _angle, char _tag);		// 初期化処理
	void Update();													// 更新処理
	void Draw() const;												// 描画処理
	bool GetActive() const;
	void SetActive(bool value);
	char GetTag() const;

};