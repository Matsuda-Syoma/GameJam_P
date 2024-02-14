#pragma once

#include "../Utility/Vector2D.h"

class HitEffect
{
private:
	int image[4];

protected:
	Vector2D location;		// 位置座標

public:
	HitEffect();
	~HitEffect();

	void Initialize(float x, float y);
	Vector2D GetLocation() const;		// 位置情報取得

	void Update();
	void Draw()const;

};