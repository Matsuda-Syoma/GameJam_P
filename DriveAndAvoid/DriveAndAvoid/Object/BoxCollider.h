#pragma once

#include "../Utility/Vector2D.h"

class BoxCollider
{
protected:
	Vector2D location;		// �ʒu���W
	Vector2D box_size;		// �����蔻��̑傫��

public:
	BoxCollider();
	~BoxCollider();

	Vector2D GetLocation() const;	// �ʒu���擾
	Vector2D GetBoxSize() const;	// �����蔻��̂��������擾

};