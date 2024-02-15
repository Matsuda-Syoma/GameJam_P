#pragma once

#include "../Utility/Vector2D.h"

class HitEffect
{
private:
	int image[4];
	bool is_active;
	int i = 0;
	int random;
protected:
	Vector2D location;		// 位置座標
	Vector2D velocity;		// 重力

public:
	HitEffect();
	~HitEffect();

	void Initialize(Vector2D loc);
	Vector2D GetLocation() const;		// 位置情報取得

	void Update();
	void Draw()const;
	bool GetActive() const;

};