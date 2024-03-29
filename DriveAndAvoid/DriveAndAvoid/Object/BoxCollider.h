#pragma once

#include "../Utility/Vector2D.h"

class BoxCollider
{
protected:
	Vector2D location;		// 位置座標
	Vector2D box_size;		// 当たり判定の大きさ

public:
	BoxCollider();
	~BoxCollider();

	Vector2D GetLocation() const;	// 位置情報取得
	Vector2D GetBoxSize() const;	// 当たり判定のおおきさ取得

};