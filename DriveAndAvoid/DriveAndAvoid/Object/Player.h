#pragma once

#include "../Utility/Vector2D.h"

class Player
{
private:
	bool is_active;			// �L����ԁH
	bool is_ground;			// �n�ʂɂ��邩
	int image;				// �摜�f�[�^
	Vector2D location;		// �ʒu���W
	Vector2D box_size;		// �����蔻��̑傫��
	Vector2D velocity;		// �d��
	float angle;			// �p�x
	float speed;			// ����
	float hp;				// �̗�

public:
	Player();
	~Player();

	void Initialize();	// ����������
	void Update();		// �X�V����
	void Draw();		// �`�揈��
	void Finalize();	// �I��������

public:
	void SetActive(bool flg);				// �L���t���O�ݒ�
	void SetGround(bool flg);				// �L���t���O�ݒ�
	void SetVelocity(float x, float y);		// Velocity�̎w��

	void DecreaseHp(float value);			// �̗͌�������
	Vector2D GetLocation() const;			// �ʒu���擾
	Vector2D GetBoxSize() const;			// �����蔻��̂��������擾
	float GetSpeed() const;					// �����擾
	float GetHp() const;					// �̗͎擾



private:
	void AddVelocity();					// �d�͏���
	void Movement();				// �ړ�����
	void Acceleration();			// ��������
};