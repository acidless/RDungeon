#pragma once
#include "Utils/Vector2.h"
#include "Utils/Subject.h"

namespace RubtidDungeon {
	class Transform : public Subject {
	public:
		Transform();

		Vector2 GetPosition();
		void SetPosition(Vector2 pos);

		Vector2 GetVelocity();
		void SetVelocityX(int velX);
		void SetVelocityY(int velY);

		void Translate(Vector2 pos);

		void Update();
	private:
		Vector2 mPos;
		Vector2 mVelocity;
	};
}