#pragma once

namespace RubtidDungeon {
	class Vector2 {
	public:
		Vector2(int _x, int _y);
		Vector2();

		bool operator==(const Vector2& vec);
		Vector2 operator*(int number);
		Vector2 operator+(const Vector2& vec);

		int x;
		int y;

		static Vector2 up;
		static Vector2 down;
		static Vector2 left;
		static Vector2 right;
	};
}