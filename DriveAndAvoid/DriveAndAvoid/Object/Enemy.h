#pragma once

#include "../Utility/Vector2D.h"
#include "BoxCollider.h"
#include "Player.h"
class GameMainScene;
class Enemy : public  BoxCollider
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
	int backflg = 0;
	int enemy_img;

	float playerx;
	float playery;
	float PX;
	float PY;
	int attackflg = 0;
	float Normalize = 0;

	Player* player;


	void BulletShoot(GameMainScene* gamemainscene, float _angle, char _tag);
public:
	Enemy();
	~Enemy();

	int count = 0;


	void SetLocation(float x, float y);		// Location�̎w��

	Vector2D GetLocation() const;			// �ʒu���擾
	Vector2D GetBoxSize() const;			// �����蔻��̂��������擾
	char GetTag() const;					// Tag�擾

	void Initialize();			// ����������
	void Update(GameMainScene* gamemainscene);	// �X�V����
	void Draw() const;			// �`�揈��
	void Finalize();			// �I��������


};