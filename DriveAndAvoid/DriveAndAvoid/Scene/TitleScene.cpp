#include "TitleScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

TitleScene::TitleScene() : background_image(NULL), menu_image(NULL),
cursor_image(NULL), menu_cursor(0)
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Initialize()
{
	// 画像の読み込み
	background_image = LoadGraph("Resource/images/Title.jpg");
	menu_image = LoadGraph("Resource/images/menu.png");
	cursor_image = LoadGraph("Resource/images/bullet.bmp");

	// エラーチェック
	if (background_image == -1)
	{
		throw ("Resource/images/Title.jpgがありません\n");
	}
	if (menu_image == -1)
	{
		throw ("Resource/images/menu.pngがありません\n");
	}
	if (cursor_image == -1)
	{
		throw ("Resource/images/bullet.bmpがありません\n");
	}
}

// 更新処理
eSceneType TitleScene::Update()
{
	// カーソル下移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;
		// 一番下に到達したら、一番上にする
		if (menu_cursor > 3)
		{
			menu_cursor = 0;
		}
	}

	// カーソル上移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		menu_cursor--;
		// 一番上に到達したら、一番下にする
		if (menu_cursor < 0)
		{
			menu_cursor = 3;
		}
	}



	// カーソル決定
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		switch (menu_cursor)
		{
		case 0:
			return eSceneType::E_MAIN;
		case 1:
			return eSceneType::E_RANKING_DISP;
		case 2:
			return eSceneType::E_HELP;
		default:
			return eSceneType::E_END;
		}
	}
	return GetNowScene();
}

// 描画処理
void TitleScene::Draw() const
{
	// タイトル画像の描画
	DrawGraph(0, 0, background_image, FALSE);

	// メニュー画像の描画
	DrawGraph(215, 320, menu_image, FALSE);

	// カーソル画像の描画
	DrawRotaGraph(185, 340 + menu_cursor * 32, 1.6, DX_PI / 200.0, cursor_image, TRUE);

}

// 終了時処理
void TitleScene::Finalize()
{
	// 読み込んだ画像の削除
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(cursor_image);
}

// 現在のシーン情報を取得
eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}