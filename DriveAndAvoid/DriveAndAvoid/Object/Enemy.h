#pragma once

#include "../Utility/Vector2D.h"

class Enemy
{
private:

	Vector2D location;		// �ʒu���W
	//Vector2D box_size;		// �����蔻��̑傫��

	int Xposition; //X���W
	int Yposition; //Y���W

	int Xspeed; //X���E�ړ����x
	int Yspeed; //Y���E�ړ����x
	int hp = 10; //��HP
	int radius; // ���ai
	int count = 0;
	int backflg = 0;
public:
	Enemy();
	~Enemy();


	void SetLocation(float x, float y);		// Location�̎w��


	Vector2D GetLocation() const;			// �ʒu���擾
	Vector2D GetBoxSize() const;			// �����蔻��̂��������擾


	void Initialize();			// ����������
	void Update();	// �X�V����
	void Draw() const;			// �`�揈��
	void Finalize();			// �I��������


};