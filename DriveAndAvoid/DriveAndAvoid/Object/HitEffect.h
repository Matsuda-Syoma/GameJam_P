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
	Vector2D location;		// �ʒu���W
	Vector2D velocity;		// �d��

public:
	HitEffect();
	~HitEffect();

	void Initialize(Vector2D loc);
	Vector2D GetLocation() const;		// �ʒu���擾

	void Update();
	void Draw()const;
	bool GetActive() const;

};