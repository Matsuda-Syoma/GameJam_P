#pragma once

#include "../Utility/Vector2D.h"

class Enemy
{
private:
	int Xposition; //X座標
	int Yposition; //Y座標

	int Xspeed; //X軸・移動速度
	int Yspeed; //Y軸・移動族度
	int hp = 10; //仮HP
	int radius; // 半径i
	int time = 0;

public:
	Enemy();
	~Enemy();

	void Initialize();			// 初期化処理
	void Update();	// 更新処理
	void Draw() const;			// 描画処理
	void Finalize();			// 終了時処理


};