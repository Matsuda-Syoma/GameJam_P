#include "BoxCollider.h"

BoxCollider::BoxCollider() : location(0.0f), box_size(0.0f)
{
}

BoxCollider::~BoxCollider()
{
}

Vector2D BoxCollider::GetLocation() const
{
	return this->location;
}

Vector2D BoxCollider::GetBoxSize() const
{
	return this->box_size;
}
