#pragma once

#include "../Utility/Vector2D.h"
#include "BoxCollider.h"
#include "Enemy.h"
class Bullet : public BoxCollider
{
private:
	bool is_active;			// �L�����ǂ���
	Vector2D velocity;		// ���x
	float angle;			// �e�̊p�x
	char tag;				// �e�̖��O
public:
	Bullet();
	~Bullet();

	void SetLocation(float x, float y);								// Location�̎w��
	Vector2D GetLocation() const;									// �ʒu���擾
	Vector2D GetVelocity() const;									// velocity���擾
	Vector2D GetBoxSize() const;									// �����蔻��̂��������擾
	float GetSpeed() const;											// �����擾
	void Initialize(Vector2D loc, float _angle, char _tag);		// ����������
	void Update();													// �X�V����
	void Draw() const;												// �`�揈��
	bool GetActive() const;
	void SetActive(bool value);
	char GetTag() const;

};