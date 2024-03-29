#include "ResultScene.h"
#include "../Object/RankingData.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

ResultScene::ResultScene() : background_image(NULL), score(0)
{
	for (int i = 0; i < 3; i++) {
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}

ResultScene::~ResultScene()
{
}

// 初期化
void ResultScene::Initialize()
{
	// 画像の読み込み
	background_image = LoadGraph("Resource/images/title.jpg");

	// エラーチェック
	if (background_image == -1)
	{
		throw("Resource/images/title.jpgがありません\n");
	}

	// ゲーム結果の読み込み
	ReadResultData();

}

// 更新処理
eSceneType ResultScene::Update()
{
	// Aボタンでランキングに遷移する
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		return eSceneType::E_RANKING_INPUT;
	}

	return GetNowScene();
}

void ResultScene::Draw() const
{

	// 背景画像を描画
	DrawGraph(0, 0, background_image, TRUE);

	// スコア等表示領域
	DrawBox(150, 150, 490, 330, GetColor(0, 153, 0), TRUE);
	DrawBox(150, 150, 490, 330, GetColor(0, 0, 0), FALSE);
}

// 終了時処理
void ResultScene::Finalize()
{
	// 読み込んだ画像を削除
	DeleteGraph(background_image);
}

eSceneType ResultScene::GetNowScene() const
{
	return eSceneType::E_RESULT;
}

void ResultScene::ReadResultData()
{
	// ファイルオープン
	FILE* fp = nullptr;
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "r");

	// エラーチェック
	if (result != 0)
	{
		throw("Resource/dat/result_data.csvが読み込めません\n");
	}

	// 結果を読み込む
	fscanf_s(fp, "%6d,\n", &score);

	// 避けた数と得点を取得
	for (int i = 0; i < 3; i++) {
		fscanf_s(fp, "%6d\n", &enemy_count[i]);
	}
	fclose(fp);
}
