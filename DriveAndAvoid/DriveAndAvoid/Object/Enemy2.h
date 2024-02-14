#pragma once

#include "../Utility/Vector2D.h"
#include "Player.h"
class Enemy
{
private:

	Vector2D location;		// �ʒu���W
	Vector2D box_size;		// �����蔻��̑傫��
	char tag;				// �^�O

	int Xposition; //X���W
	int Yposition; //Y���W

	int Xspeed; //X���E�ړ����x
	int Yspeed; //Y���E�ړ����x
	int hp; //��HP
	int radius; // ���a
	int enemy_img;

	float playerx;
	float playery;
	float PX;
	float PY;
	int attackflg = 0;

	Player* player;
public:
	Enemy();
	~Enemy();

	int count = 0;


	void SetLocation(float x, float y);		// Location�̎w��

	Vector2D GetLocation() const;			// �ʒu���擾
	Vector2D GetBoxSize() const;			// �����蔻��̂��������擾

	void Initialize();			// ����������
	void Update(GameMainScene* gamemain);		// �X�V����
	void Draw() const;			// �`�揈��
	void Finalize();			// �I��������


};