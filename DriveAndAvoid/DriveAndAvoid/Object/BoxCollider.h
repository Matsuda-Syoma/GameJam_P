#pragma once

#include "../Utility/Vector2D.h"

class BoxCollider
{
protected:
	Vector2D location;		// ˆÊ’uÀ•W
	Vector2D box_size;		// “–‚½‚è”»’è‚Ì‘å‚«‚³

public:
	BoxCollider();
	~BoxCollider();

	Vector2D GetLocation() const;	// ˆÊ’uî•ñæ“¾
	Vector2D GetBoxSize() const;	// “–‚½‚è”»’è‚Ì‚¨‚¨‚«‚³æ“¾

};