#include "LoadStage.h"
#include "DxLib.h"

int LoadStage::data[20][15];
int LoadStage::row;

// �R���X�g���N�^
LoadStage::LoadStage()
{
	int fp;
	char buf[10];
	char c;
	int col = 1;	// csv�t�@�C���̗�
	row = 0;		// csv�t�@�C���̍s
	int count = 0;

	memset(buf, 0, sizeof(buf));

	// �t�@�C���̃��[�h
	fp = FileRead_open("Resource/Stagedata.csv");

	// 1�s�ڂ𖳎�����
	while (FileRead_getc(fp) != '\n');

	// �f�[�^�̓ǂݍ���
	while (1) {
		while (1) {

			// �t�@�C����1�������擾�A������ɂ���
			c = FileRead_getc(fp);
			buf[count] = c;

			// �J���}�A���s�AEOF�Ȃ烋�[�v�𔲂���
			if (c == ',' || c == '\n' || c == EOF) {
				buf[count] = '\0';
				break;
			}
			count++;
		}

		data[col][row] = atoi(buf);

		memset(buf, 0, sizeof(buf));

		// EOF�Ȃ�out�ɔ��
		if (c == EOF) {
			goto out;
		}

		// EOF�ʂ�Ȃ������Ȃ�ǂݍ��ވʒu�����������Ď��̗��ǂ�
		count = 0;
		col++;

		// ���s�Ȃ玟�̍s�ɍs��
		if (c == '\n') {
			col = 1;
			++row;
		}
	}
out:
	FileRead_close(fp);
}


LoadStage::~LoadStage()
{

}
