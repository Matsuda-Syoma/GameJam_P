#pragma once

class LoadStage
{
private:

	static int data[20][15];			// �G�̐��̍ő吔
	static int row;						// csv�t�@�C���̗�̐�(�ǂݍ��܂���)
public:
	LoadStage();						// �R���X�g���N�^
	~LoadStage();						// �f�X�g���N�^
	//static ENEMYDATA LoadEnemy(int i);	// �G���̓ǂݍ���
};