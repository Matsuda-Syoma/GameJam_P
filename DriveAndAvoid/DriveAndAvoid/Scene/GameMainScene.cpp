#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene() :high_score(0), background_image(NULL), mileage(0), player(nullptr),
enemy(nullptr) {
	for (int i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
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
	enemy = new Enemy * [10];

	// オブジェクトの初期化
	player->Initialize();

	for (int i = 0; i < 10; i++) {
		enemy[i] = nullptr;
	}
}

eSceneType GameMainScene::Update()
{
	//// プレイヤーの更新
	//player->Update();

	return GetNowScene();
}

void GameMainScene::Draw() const
{
	// 背景画像の描画
	DrawGraph(0, mileage % 480 - 480, background_image, TRUE);
	DrawGraph(0, mileage % 480, background_image, TRUE);

	// 敵の描画
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	// プレイヤーの描画
	player->Draw();

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

	// 位置情報の差分取得
	Vector2D diff_location = p->GetLocation() - e->GetLocation();

	// 当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + e->GetBoxSize();
	// コリジョンデータより位置情報の差分が小さいなら、ヒット判定
	return ((fabs(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}
