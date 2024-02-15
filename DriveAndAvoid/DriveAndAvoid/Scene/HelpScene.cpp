#include "HelpScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"


HelpScene::HelpScene() : background_image(NULL),text_image(NULL)
{
}

HelpScene::~HelpScene()
{
}

void HelpScene::Initialize()
{
    // 画像の読み込み
    background_image = LoadGraph("Resource/images/Title.jpg");
    text_image = LoadGraph("Resource/images/Help.png");
    setumei_image = LoadGraph("Resource/images/setumei.png");

    // エラーチェック
    if (background_image == -1)
    {
        throw("Resource/images/Title.jpgがありません\n");
    }
    if (text_image == -1)
    {
        throw("Resource/images/Help.pngがありません\n");
    }
    if (setumei_image == -1)
    {
        throw("Resource/images/setumei.pngがありません\n");
    }
}

// 初期化
eSceneType HelpScene::Update()
{
    // Aボタンが押されたら、タイトルに戻る
    if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
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
    DrawGraph(0, 0, text_image, FALSE);
    DrawGraph(130, 110, setumei_image, FALSE);

    //タイトルへ戻る文字
    DrawString(200, 450, "タイトルへ戻る    Aボタン", GetColor(0,0,0));
}

// 終了時処理
void HelpScene::Finalize()
{
    // 読み込んだ画像を削除
    DeleteGraph(background_image);
    DeleteGraph(text_image);
    DeleteGraph(setumei_image);
}

// 現在のシーン
eSceneType HelpScene::GetNowScene() const
{
    return eSceneType::E_HELP;
}
