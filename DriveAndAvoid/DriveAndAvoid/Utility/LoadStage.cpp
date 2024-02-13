#include "LoadStage.h"
#include "DxLib.h"

int LoadStage::data[20][15];
int LoadStage::row;

// コンストラクタ
LoadStage::LoadStage()
{
	int fp;
	char buf[10];
	char c;
	int col = 1;	// csvファイルの列
	row = 0;		// csvファイルの行
	int count = 0;

	memset(buf, 0, sizeof(buf));

	// ファイルのロード
	fp = FileRead_open("Resource/Stagedata.csv");

	// 1行目を無視する
	while (FileRead_getc(fp) != '\n');

	// データの読み込み
	while (1) {
		while (1) {

			// ファイルの1文字を取得、文字列にする
			c = FileRead_getc(fp);
			buf[count] = c;

			// カンマ、改行、EOFならループを抜ける
			if (c == ',' || c == '\n' || c == EOF) {
				buf[count] = '\0';
				break;
			}
			count++;
		}

		data[col][row] = atoi(buf);

		memset(buf, 0, sizeof(buf));

		// EOFならoutに飛ぶ
		if (c == EOF) {
			goto out;
		}

		// EOF通らなかったなら読み込む位置を初期化して次の列を読む
		count = 0;
		col++;

		// 改行なら次の行に行く
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
