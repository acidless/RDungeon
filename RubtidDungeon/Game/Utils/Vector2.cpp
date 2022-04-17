#include "Vector2.h"

RubtidDungeon::Vector2::Vector2(int _x, int _y) : x(_x), y(_y)
{
}

RubtidDungeon::Vector2::Vector2() : x(0), y(0)
{
}

bool RubtidDungeon::Vector2::operator==(const Vector2& vec)
{
	return vec.x == x && vec.y == y;
}

RubtidDungeon::Vector2 RubtidDungeon::Vector2::operator*(int number)
{
	return Vector2(x * number, y * number);
}

RubtidDungeon::Vector2 RubtidDungeon::Vector2::operator+(const Vector2& vec)
{
	return Vector2(x + vec.x, y + vec.y);
}

RubtidDungeon::Vector2 RubtidDungeon::Vector2::up = Vector2(0, -1);
RubtidDungeon::Vector2 RubtidDungeon::Vector2::down = Vector2(0, 1);
RubtidDungeon::Vector2 RubtidDungeon::Vector2::left = Vector2(-1, 0);
RubtidDungeon::Vector2 RubtidDungeon::Vector2::right = Vector2(1, 0);