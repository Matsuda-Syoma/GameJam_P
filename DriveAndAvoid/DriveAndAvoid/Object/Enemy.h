#pragma once

#include "../Utility/Vector2D.h"

class Enemy
{
private:
	int Xposition; //X���W
	int Yposition; //Y���W

	int Xspeed; //X���E�ړ����x
	int Yspeed; //Y���E�ړ����x
	int hp = 10; //��HP
	int radius; // ���ai
	int time = 0;

public:
	Enemy();
	~Enemy();

	void Initialize();			// ����������
	void Update();	// �X�V����
	void Draw() const;			// �`�揈��
	void Finalize();			// �I��������


};