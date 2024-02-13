#pragma once

#include "../Utility/Vector2D.h"
#include "Enemy.h"
class Bullet
{
private:
	Vector2D location;		// �ʒu���W
	Vector2D box_size;		// �����蔻��̑傫��
	Vector2D GetLocation() const;			// �ʒu���擾

	int radius; // ���a
	int speed; //�e�̃X�s�[�h
	int bulletx;
	int bullety;
	int x, y;
public:
	Bullet(int ex,int ey);
	~Bullet();

	void SetLocation(float x, float y);		// Location�̎w��


	void Initialize();			// ����������
	void Update();	// �X�V����
	void Draw() const;			// �`�揈��
};