#pragma once

#include "../Utility/Vector2D.h"

class Block
{
private:
	int image;				// 画像データ
	Vector2D location;		// 位置座標
	Vector2D box_size;		// 当たり判定の大きさ

public:
	Block(int handle);
	~Block();

	void Initialize(int x, int y);			// 初期化処理
	void Draw() const;			// 描画処理
	void Finalize();			// 終了時処理

	Vector2D GetLocation() const;	// 位置情報取得
	Vector2D GetBoxSize() const;	// 当たり判定のおおきさ取得

};