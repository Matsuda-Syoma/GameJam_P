#pragma once

#include "../Utility/Vector2D.h"

class Block
{
private:
	int image;				// �摜�f�[�^
	Vector2D location;		// �ʒu���W
	Vector2D box_size;		// �����蔻��̑傫��

public:
	Block(int handle);
	~Block();

	void Initialize(int x, int y);			// ����������
	void Draw() const;			// �`�揈��
	void Finalize();			// �I��������

	Vector2D GetLocation() const;	// �ʒu���擾
	Vector2D GetBoxSize() const;	// �����蔻��̂��������擾

};