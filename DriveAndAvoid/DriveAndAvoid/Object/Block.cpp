#include "Block.h"
#include "DxLib.h"

Block::Block(int handle) : image(handle), location(0.0f), box_size(0.0f)
{
}

Block::~Block()
{
}

void Block::Initialize(int x, int y)
{
	location = Vector2D((float)x * 32, (float)y * 32);
	box_size = Vector2D(32.0f, 32.0f);

	//画像の読み込み
	image = LoadGraph("Resource/images/block1.bmp");

	//エラーチェック
	if (image == -1)
	{
		throw("Resource/images/block1.bmpがありません。\n");
	}
}

void Block::Draw() const
{
	// 画像の描画
	DrawBox(location.x, location.y, location.x + box_size.x, location.y + box_size.y, 0xffffff, true);
	DrawGraph(location.x, location.y, image, TRUE);
}

void Block::Finalize()
{
}

Vector2D Block::GetLocation() const
{
	return location;
}

Vector2D Block::GetBoxSize() const
{
	return box_size;
}
