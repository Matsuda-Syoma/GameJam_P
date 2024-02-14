#pragma once

#include "../Utility/Vector2D.h"

class HitEffect
{
private:
	int image[4];

protected:
	Vector2D location;		// �ʒu���W

public:
	HitEffect();
	~HitEffect();

	void Initialize(float x, float y);
	Vector2D GetLocation() const;		// �ʒu���擾

	void Update();
	void Draw()const;

};