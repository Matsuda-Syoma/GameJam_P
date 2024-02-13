#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene() :high_score(0), background_image(NULL), mileage(0), player(nullptr),
enemy(nullptr),block(nullptr) {
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
	block = new Block * [300];

	// オブジェクトの初期化
	player->Initialize();

	for (int i = 0; i < 10; i++) {
		enemy[i] = nullptr;
	}
	for (int i = 0; i < 300; i++) {
		block[i] = nullptr;
	}

	block[0] = new Block(0);
	block[0]->Initialize(10, 8);

	//for (int i = 0; i < 20; i++) {
	//	block[i] = new Block(0);
	//	block[i]->Initialize(i, 14);
	//}
}

eSceneType GameMainScene::Update()
{
	player->SetGround(false);
	// 敵の更新と当たり判定チェック
	for (int i = 0; i < 300; i++)
	{
		// 値がnullでないなら
		if (block[i] != nullptr)
		{
			// 当たり判定の確認
			if (IsHitCheck(player, block[i]))
			{
				player->SetVelocity(0,0);
				player->SetLocation(player->GetLocation().x, block[i]->GetLocation().y - block[i]->GetBoxSize().y);
			}
			if (IsGroundCheck(player, block[i]))
			{
				player->SetGround(true);
			}
		}
	}
	// プレイヤーの更新
	player->Update();

	return GetNowScene();
}

void GameMainScene::Draw() const
{
	//// 背景画像の描画
	//DrawGraph(0, mileage % 480 - 480, background_image, TRUE);
	//DrawGraph(0, mileage % 480, background_image, TRUE);

	//// 敵の描画
	//for (int i = 0; i < 10; i++)
	//{
	//	if (enemy[i] != nullptr)
	//	{
	//		enemy[i]->Draw();
	//	}
	//}

	// ブロックの描画
	for (int i = 0; i < 300; i++)
	{
		if (block[i] != nullptr)
		{
			block[i]->Draw();
		}

	}

	//// プレイヤーの描画
	player->Draw();

	//UIの描画
	DrawBox(5,10,130,45, GetColor(0,0,153), TRUE);
	SetFontSize(16);
	DrawFormatString(285, 425, GetColor(255,255,255), "SCORE");
	DrawFormatString(272, 442, GetColor(255, 255, 255), "%08d", score);
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

// あたり判定処理（プレイヤーとブロック）
bool GameMainScene::IsHitCheck(Player* p, Block* b)
{

	// 敵情報がなければ、当たり判定を無視する
	if (b == nullptr) {
		return false;
	}

	// 位置情報の差分取得
	Vector2D diff_location = p->GetLocation() - b->GetLocation();

	// 当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + b->GetBoxSize();
	// コリジョンデータより位置情報の差分が小さいなら、ヒット判定
	return ((fabs(diff_location.x) < box_ex.x / 2) && (fabsf(diff_location.y) < box_ex.y / 2));
}



// 地面にいるか確認処理（プレイヤーとブロック）
bool GameMainScene::IsGroundCheck(Player* p, Block* b)
{

	// 敵情報がなければ、当たり判定を無視する
	if (b == nullptr) {
		return false;
	}

	// 位置情報の差分取得
	Vector2D diff_location = p->GetLocation() - b->GetLocation();
	diff_location += Vector2D(0.0f, 0.1f);

	// 当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + b->GetBoxSize();
	// コリジョンデータより位置情報の差分が小さいなら、ヒット判定
	return ((fabs(diff_location.x) < box_ex.x / 2) && (fabsf(diff_location.y) < box_ex.y / 2));
}