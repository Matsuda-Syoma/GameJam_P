#pragma once

#include "../Utility/Vector2D.h"

class Enemy
{
private:
	int type;				// �^�C�v
	int image;				// �摜�f�[�^
	Vector2D location;		// �ʒu���W
	Vector2D box_size;		// �����蔻��̑傫��
	float speed;			// ����

public:
	Enemy(int type, int handle);
	~Enemy();

	void Initialize();			// ����������
	void Update(float speed);	// �X�V����
	void Draw() const;			// �`�揈��
	void Finalize();			// �I��������

	int GetType() const;			// �^�C�v�擾
	Vector2D GetLocation() const;	// �ʒu���擾
	Vector2D GetBoxSize() const;	// �����蔻��̂��������擾

};