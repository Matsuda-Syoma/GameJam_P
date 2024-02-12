#include "HelpScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"


HelpScene::HelpScene() : background_image(NULL)
{
}

HelpScene::~HelpScene()
{
}

void HelpScene::Initialize()
{
    // 画像の読み込み
    background_image = LoadGraph("Resource/images/Title.bmp");

    // エラーチェック
    if (background_image == -1) {
        throw("Resource/images/Title.bmpがありません\n");
    }

}

// 初期化
eSceneType HelpScene::Update()
{
    // Bボタンが押されたら、タイトルに戻る
    if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
    {
        return eSceneType::E_TITLE;
    }
    return GetNowScene();
}

// 描画
void HelpScene::Draw() const
{
    // 背景の描画
    DrawGraph(0, 0, background_image, FALSE);
}

// 終了時処理
void HelpScene::Finalize()
{
    // 読み込んだ画像を削除
    DeleteGraph(background_image);
}

// 現在のシーン
eSceneType HelpScene::GetNowScene() const
{
    return eSceneType::E_HELP;
}
