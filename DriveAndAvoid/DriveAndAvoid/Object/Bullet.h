#pragma once

#include "../Utility/Vector2D.h"
#include "Enemy.h"
class Bullet
{
private:
	Vector2D location;		// 位置座標
	Vector2D box_size;		// 当たり判定の大きさ
	Vector2D GetLocation() const;			// 位置情報取得

	int radius; // 半径
	int speed; //弾のスピード
	int bulletx;
	int bullety;
	int x, y;
public:
	Bullet(int ex,int ey);
	~Bullet();

	void SetLocation(float x, float y);		// Locationの指定


	void Initialize();			// 初期化処理
	void Update();	// 更新処理
	void Draw() const;			// 描画処理
};