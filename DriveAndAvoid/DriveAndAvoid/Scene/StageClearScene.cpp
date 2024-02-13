#include "StageClearScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"


StageClearScene::StageClearScene() : background_image(NULL)
{

}

StageClearScene::~StageClearScene()
{

}

void StageClearScene::Initialize()
{
	// 画像の読み込み
	background_image = LoadGraph("Resource/images/StageClear.jpg");

	// エラーチェック
	if (background_image == -1)
	{
		throw ("Resource/images/StageClear.jpgがありません\n");
	}
}

// 更新処理
eSceneType StageClearScene::Update()
{
	//Aボタンで次のステージに遷移する
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		return eSceneType::E_MAIN;
	}

	return GetNowScene();
}

// 描画処理
void StageClearScene::Draw() const
{
	//ステージクリア画像の描画
	DrawGraph(0, 0, background_image, FALSE);

}

// 終了時処理
void StageClearScene::Finalize()
{
	// 読み込んだ画像の削除
	DeleteGraph(background_image);

}

// 現在のシーン情報を取得
eSceneType StageClearScene::GetNowScene() const
{
	return eSceneType::E_STAGECLEAR;
}
