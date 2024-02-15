#pragma once

#include "../Utility/Vector2D.h"
#include "BoxCollider.h"
#include "Player.h"
class Enemy2 : public  BoxCollider
{
private:
	Vector2D velocity;		// �d��
	char tag;				// �^�O

	bool is_ground;			// �n�ʂɂ��邩


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
	int hit;
	int hpflg = 0;
	int hpber;

	Player* player;
public:
	Enemy2();
	~Enemy2();

	int count = 0;


	void SetLocation(float x, float y);		// Location�̎w��
	
	Vector2D GetLocation() const;			// �ʒu���擾
	Vector2D GetBoxSize() const;			// �����蔻��̂��������擾
	char GetTag() const;					// Tag�擾

	void Initialize();			// ����������
	void Update(GameMainScene* gamemain);		// �X�V����
	void Draw() const;			// �`�揈��

	void AddVelocity();					// �d�͏���
	void SetGround(bool flg);				// �n�ʂɂ��邩�ݒ�
	bool GetGround() const;				// �̗͌�������
	Vector2D GetVelocity() const;			// velocity���擾
	void SetVelocity(float x, float y);		// Velocity�̎w��
	void Setcount(int  x);		


};