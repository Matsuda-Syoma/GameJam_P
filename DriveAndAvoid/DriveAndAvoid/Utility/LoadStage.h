#pragma once

class LoadStage
{
private:

	static int data[20][15];			// 敵の数の最大数
	static int row;						// csvファイルの列の数(読み込まれる量)
public:
	LoadStage();						// コンストラクタ
	~LoadStage();						// デストラクタ
	//static ENEMYDATA LoadEnemy(int i);	// 敵情報の読み込み
};