#pragma once

#include "../Utility/Vector2D.h"

class HitEffect
{
private:
	int image[4];

protected:
	Vector2D location;		// ˆÊ’uÀ•W

public:
	HitEffect();
	~HitEffect();

	void Initialize(float x, float y);
	Vector2D GetLocation() const;		// ˆÊ’uî•ñæ“¾

	void Update();
	void Draw()const;

};