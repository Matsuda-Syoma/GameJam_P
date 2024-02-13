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
}

void Block::Draw() const
{
	// ‰æ‘œ‚Ì•`‰æ
	DrawBox(location.x, location.y, location.x + box_size.x, location.y + box_size.y, 0xffffff, true);
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
