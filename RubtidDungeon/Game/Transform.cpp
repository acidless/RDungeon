#include "Transform.h"
#include <iostream>

RubtidDungeon::Transform::Transform() : mPos(Vector2()) {

}

RubtidDungeon::Vector2 RubtidDungeon::Transform::GetPosition()
{
	return mPos;
}

void RubtidDungeon::Transform::SetPosition(Vector2 pos)
{
	mPos = pos;
	Emit("posChange");
}

RubtidDungeon::Vector2 RubtidDungeon::Transform::GetVelocity()
{
	return mVelocity;
}

void RubtidDungeon::Transform::SetVelocityX(int velX)
{
	mVelocity.x = velX;
}

void RubtidDungeon::Transform::SetVelocityY(int velY)
{
	mVelocity.y = velY;
}

void RubtidDungeon::Transform::Translate(Vector2 pos)
{
	SetPosition(mPos + pos);
}

void RubtidDungeon::Transform::Update()
{
	SetPosition(mPos + mVelocity);
}
