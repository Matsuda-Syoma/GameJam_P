#include "StageClearScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"


StageClearScene::StageClearScene() : background_image(NULL),text_image(NULL),mob_image(NULL)
{

}

StageClearScene::~StageClearScene()
{

}

void StageClearScene::Initialize()
{
	// 画像の読み込み
	background_image = LoadGraph("Resource/images/StageClearScene.png");
	text_image = LoadGraph("Resource/images/StageClear.png");
	mob_image = LoadGraph("Resource/images/mob.bmp");

	// エラーチェック
	if (background_image == -1)
	{
		throw ("Resource/images/StageClearScene.pngがありません\n");
	}
	if (text_image == -1)
	{
		throw("Resource/images/StageClear.pngがありません\n");
	}
	if (mob_image == -1)
	{
		throw("Resource/images/mob.bmpがありません\n");
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
	//ステージクリアテキスト画像の描画
	DrawGraph(5, 45, text_image, FALSE);
	//ステージクリア画面時のキャラクター描画
	DrawGraph(290, 250, mob_image, FALSE);

	//次のシーンへ切り替え
	DrawString(200, 430, "次のステージ    Aボタン", 0xffffff);
}

// 終了時処理
void StageClearScene::Finalize()
{
	// 読み込んだ画像の削除
	DeleteGraph(background_image);
	DeleteGraph(text_image);
	DeleteGraph(mob_image);
}

// 現在のシーン情報を取得
eSceneType StageClearScene::GetNowScene() const
{
	return eSceneType::E_STAGECLEAR;
}
