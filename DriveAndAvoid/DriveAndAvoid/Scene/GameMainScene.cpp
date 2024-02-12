#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>
GameMainScene::GameMainScene() :high_score(0), background_image(NULL), mileage(0), player(nullptr),
enemy() {



}

GameMainScene::~GameMainScene()
{
}

void GameMainScene::Initialize()
{
	// 最高点を読み込む
	ReadHighScore();

	// 画像の読み込み
	background_image = LoadGraph("Resource/images/back.bmp");
	int result = LoadDivGraph("Resource/images/car.bmp", 3, 3, 1, 63, 120, enemy_image);
	// エラーチェック
	if (background_image == -1) {
		throw("画像back.bmpがありません\n");
	}
	if (result == -1) {
		throw("画像car.bmpがありません\n");
	}

	// オブジェクトの生成
	player = new Player;

	// オブジェクトの初期化
	player->Initialize();

	enemy = new Enemy;

	enemy->Initialize();

}

eSceneType GameMainScene::Update()
{
	//// プレイヤーの更新
	//player->Update();
	enemy->Update();

	return GetNowScene();
}

void GameMainScene::Draw() const
{
	//// 背景画像の描画
	//DrawGraph(0, mileage % 480 - 480, background_image, TRUE);
	//DrawGraph(0, mileage % 480, background_image, TRUE);



	//// プレイヤーの描画
	//player->Draw();

	enemy->Draw();
}

void GameMainScene::Finalize()
{

}

// 現在のシーン情報取得
eSceneType GameMainScene::GetNowScene() const
{
	return eSceneType::E_MAIN;
}

// ハイスコア読込
void GameMainScene::ReadHighScore()
{
}

// あたり判定処理（プレイヤーと敵）
bool GameMainScene::IsHitCheck(Player* p, Enemy* e)
{

	// 敵情報がなければ、当たり判定を無視する
	if (e == nullptr) {
		return false;
	}

	
}
