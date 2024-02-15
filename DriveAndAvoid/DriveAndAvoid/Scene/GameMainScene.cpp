#include "GameMainScene.h"
#include "Dxlib.h"
#include <math.h>

#include "../Utility/InputControl.h"
GameMainScene::GameMainScene() :score(0), high_score(0), background_image(NULL), mileage(0), player(nullptr),
enemy(nullptr),block(nullptr),bullet(nullptr),enemy2(nullptr) {


}

GameMainScene::~GameMainScene()
{
}

void GameMainScene::Initialize()
{
	// 最高点を読み込む
	ReadHighScore();
	LoadStage::LoadStage();
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
	enemy2 = new Enemy2 * [10];
	block = new Block * [300];
	bullet = new Bullet * [30];
	hiteffect = new HitEffect * [30];
	// オブジェクトの初期化
	player->Initialize();


	
	//敵1
	for (int i = 0; i < 10; i++) {
		enemy[i] = nullptr;
	}
	//敵2
	for (int i = 0; i < 10; i++) {
		enemy2[i] = nullptr;
	}
	for (int i = 0; i < 300; i++) {
		block[i] = nullptr;
	}
	for (int i = 0; i < 30; i++) {
		bullet[i] = nullptr;
	}

	//敵1
	for (int i = 0; i < 30; i++) {
		hiteffect[i] = nullptr;
	}
	enemy[0] = new Enemy();
	enemy[0]->Initialize();
	//敵2
	enemy2[0] = new Enemy2();
	enemy2[0]->Initialize();

	int num = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 15; j++) {
			if (LoadStage::LoadBlock(i, j) != 0)
			{
				block[num] = new Block(0);
				block[num]->Initialize(i ,j);
				num++;
			}
		}
	}


}

eSceneType GameMainScene::Update()
{

	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		return E_RESULT;
	}

	// プレイヤー
	// プレイヤーが地面にいるかチェック
	player->SetGround(false);
	for (int i = 0; i < 300; i++)
	{
		// 値がnullでないなら
		if (block[i] != nullptr)
		{
			if (IsGroundCheck(player, block[i]))
			{
				player->SetVelocity(0, 0);
				player->SetGround(true);
			}
		}
	}


	// 敵2が地面にいるかチェック
	if (enemy2[0] != nullptr)
	{

		enemy2[0]->SetGround(false);
		for (int i = 0; i < 300; i++)
		{
			// 値がnullでないなら
			if (block[i] != nullptr)
			{
				if (IsGroundCheck(enemy2[0], block[i]))
				{
					enemy2[0]->SetVelocity(0, 0);
					enemy2[0]->SetGround(true);
				}
			}
		}
	}



	// プレイヤーの更新
	player->Update(this);
	if (player->GetHp() <= 0)
	{
		return E_RESULT;
	}
	// ブロックとプレイヤーの当たり判定チェック
	for (int i = 0; i < 300; i++)
	{
		// 値がnullでないなら
		if (block[i] != nullptr)
		{
			// 当たり判定の確認
			if (int value = IsHitCheck(player, block[i]))
			{
				switch (value)
				{
					// プレイヤーの左のブロックに当たったとき
				case 1:
					player->SetLocation(block[i]->GetLocation().x + block[i]->GetBoxSize().x, player->GetLocation().y);
					break;
					// プレイヤーの上のブロックに当たったとき
				case 2:
					player->SetVelocity(player->GetVelocity().x, player->GetVelocity().y / 2);
					player->SetLocation(player->GetLocation().x, block[i]->GetLocation().y + block[i]->GetBoxSize().y);
					break;
					// プレイヤーの右のブロックに当たったとき
				case 3:
					player->SetLocation(block[i]->GetLocation().x - block[i]->GetBoxSize().x, player->GetLocation().y);
					break;
					// プレイヤーの下のブロックに当たったとき
				case 4:
					player->SetLocation(player->GetLocation().x, block[i]->GetLocation().y - block[i]->GetBoxSize().y);
					break;
				}
			}
		}
	}


	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		return E_RESULT;
	}

	//敵1
	if (enemy[0] != nullptr)
	{
		// 敵の更新
		enemy[0]->SetLocation(player->GetLocation().x, player->GetLocation().y);
		enemy[0]->Update(this);
	}

	//敵2
	if (enemy2[0] != nullptr)
	{
		// 敵の更新
		enemy2[0]->SetLocation(player->GetLocation().x, player->GetLocation().y);
		enemy2[0]->Update(this);
	}


	//敵1
	for (int i = 0; i < 30; i++)
	{
		// 値がnullでないなら
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();
			if (IsHitCheck(player,bullet[i]) && player->GetTag() != bullet[i]->GetTag())
			{
				SpawnHitEffect(player->GetLocation());
				player->DecreaseHp(-10.0);
				bullet[i]->SetActive(false);
			}
			for (int j = 0; j < 10; j++)
			{
				if (enemy[j] != nullptr)
				{
					if (IsHitCheck(enemy[j], bullet[i]) && enemy[j]->GetTag() != bullet[i]->GetTag())
					{
						SpawnHitEffect(enemy[j]->GetLocation());
						bullet[i]->SetActive(false);

						hit = hit + 1; //hitカウント
						enemyflg = 1;
						enemy[0]->SetEnemy(hit,enemyflg);
						enemyflg = 0;
					}
				}
			}
			if (!bullet[i]->GetActive())
			{
				bullet[i] = nullptr;
				delete bullet[i];
			}
		}
	}

	//敵2
	for (int i = 0; i < 30; i++)
	{
		// 値がnullでないなら
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();
			if (IsHitCheck(player, bullet[i]) && player->GetTag() != bullet[i]->GetTag())
			{
				SpawnHitEffect(player->GetLocation());
				bullet[i]->SetActive(false);
			}
			for (int j = 0; j < 10; j++)
			{
				if (enemy2[j] != nullptr)
				{
					if (IsHitCheck(enemy2[j], bullet[i]) && enemy2[j]->GetTag() != bullet[i]->GetTag())
					{
						SpawnHitEffect(enemy2[j]->GetLocation());
						bullet[i]->SetActive(false);

						hit2 = hit2 + 1; //hitカウント
						enemyflg = 1;
						enemy2[0]->SetEnemy(hit2,enemyflg);
						enemyflg = 0;
					}
				}
			}
			if (!bullet[i]->GetActive())
			{
				bullet[i] = nullptr;
				delete bullet[i];
			}
		}
	}

	for (int i = 0; i < 30; i++)
	{
		// 値がnullでないなら
		if (hiteffect[i] != nullptr)
		{
			hiteffect[i]->Update();
			if (!hiteffect[i]->GetActive())
			{
				hiteffect[i] = nullptr;
				delete hiteffect[i];
			}
		}
	}

	return GetNowScene();
}

void GameMainScene::Draw() const
{
	//DrawGraph(0, mileage % 480 - 480, background_image, TRUE);
	//DrawGraph(0, mileage % 480, background_image, TRUE);


	// ブロックの描画
	for (int i = 0; i < 300; i++)
	{
		if (block[i] != nullptr)
		{
			block[i]->Draw();
		}

	}

	// プレイヤーの描画
	player->Draw();

	//敵1
	if (enemy[0] != nullptr)
	{
		// 敵の描画
		enemy[0]->Draw();
	}

	//敵2
	if (enemy2[0] != nullptr)
	{
		// 敵の描画
		enemy2[0]->Draw();
	}

	for (int i = 0; i < 30; i++)
	{
		// 値がnullでないなら
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}

	for (int i = 0; i < 30; i++)
	{
		// 値がnullでないなら
		if (hiteffect[i] != nullptr)
		{
			hiteffect[i]->Draw();
		}
	}

	//UIの描画
	DrawBox(5,10,220,45, GetColor(255,153,233), TRUE);
	DrawBox(10, 15, 10 + (player->GetHp() / 100) * 205, 40, GetColor(125, 127, 153), TRUE);
	SetFontSize(16);
	DrawFormatString(285, 25, GetColor(255,255,255), "SCORE");
	DrawFormatString(272, 42, GetColor(255, 255, 255), "%08d", score);
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
bool GameMainScene::IsHitCheck(BoxCollider* p, BoxCollider* e)
{

	// 敵情報がなければ、当たり判定を無視する
	if (e == nullptr) {
		return false;
	}

	// 位置情報の差分取得
	Vector2D diff_location = p->GetLocation() - e->GetLocation();

	// 当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + e->GetBoxSize();
	//clsDx();
	//printfDx("%f %f", diff_location.x, box_ex.x);
	// コリジョンデータより位置情報の差分が小さいなら、ヒット判定
	return ((fabs(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

// あたり判定処理（プレイヤーとブロック）
int GameMainScene::IsHitCheck(Player* p, Block* b)
{

	// 敵情報がなければ、当たり判定を無視する
	if (b == nullptr) {
		return 0;
	}

	// 位置情報の差分取得
	Vector2D diff_location = p->GetLocation() - b->GetLocation();
	// 当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + b->GetBoxSize();
	// 当たっているなら入る
	if ((fabs(diff_location.x) < box_ex.x / 2) && (fabsf(diff_location.y) < box_ex.y / 2))
	{
		// 一時保存用変数の作成
		Vector2D work_vector = 0.0f;
		Vector2D work_vector2 = 0.0f;
		Vector2D min_vector = 0.0f;
		int select[2] = { 0 };
		int finret = 0;

		// 対象の座標と当たり判定を足した変数の作成
		// プレイヤー
		Vector2D p_location = p->GetLocation();
		Vector2D p_location2 = p->GetLocation() + p->GetBoxSize();

		// ブロック
		Vector2D b_location = b->GetLocation();
		Vector2D b_location2 = b->GetLocation() + b->GetBoxSize();

		// 上下左右の距離を保存
		work_vector.x = fabsf(p_location.x - b_location2.x);
		work_vector2.x = fabsf(p_location2.x - b_location.x);
		work_vector.y = fabsf(p_location.y - b_location2.y);
		work_vector2.y = fabsf(p_location2.y - b_location.y);

		// 横の小さい距離を条件で確認、保存
		if (work_vector.x < work_vector2.x)
		{
			min_vector.x = work_vector.x;
			select[0] = 1;
		}
		else
		{
			min_vector.x = work_vector2.x;
			select[0] = 3;
		}

		// 縦の小さい距離を条件で確認、保存
		if (work_vector.y < work_vector2.y)
		{
			min_vector.y = work_vector.y;
			select[1] = 2;
		}
		else
		{
			min_vector.y = work_vector2.y;
			select[1] = 4;
		}

		// 縦横の小さい距離を条件で確認、Returnで返す
		if (min_vector.x < min_vector.y)
		{
			finret = select[0];
		}
		else
		{
			finret = select[1];
		}
		return finret;
	}
	return 0;
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

// 地面にいるか確認処理（エネミーとブロック）
bool GameMainScene::IsGroundCheck(Enemy2* e, Block* b)
{

	// 敵情報がなければ、当たり判定を無視する
	if (b == nullptr) {
		return false;
	}

	// 位置情報の差分取得
	Vector2D diff_location = e->GetLocation() - b->GetLocation();
	diff_location += Vector2D(0.0f, 0.1f);

	// 当たり判定サイズの大きさを取得
	Vector2D box_ex = e->GetBoxSize() + b->GetBoxSize();
	// コリジョンデータより位置情報の差分が小さいなら、ヒット判定
	return ((fabs(diff_location.x) < box_ex.x / 2) && (fabsf(diff_location.y) < box_ex.y / 2));
}

Player* GameMainScene::GetPlayer()
{
	return this->player;
}

void GameMainScene::SpawnBullet(Vector2D loc, float _angle, char _tag)
{
	for (int i = 0; i < 30; i++) {
		if (bullet[i] == nullptr) {
			bullet[i] = new Bullet();
			bullet[i]->Initialize(loc, _angle, _tag);
			break;
		}
	}

}

void GameMainScene::SpawnHitEffect(Vector2D loc)
{
	for (int i = 0; i < 30; i++) {
		if (hiteffect[i] == nullptr) {
			hiteffect[i] = new HitEffect();
			hiteffect[i]->Initialize(loc);
			break;
		}
	}

}