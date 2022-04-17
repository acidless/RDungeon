#pragma once
#include "../Object.h"
#include "../Transform.h"

namespace RubtidDungeon {
	namespace Components {
		class Component : public Object {
		public:
			Component(Transform* _transform) : transform(_transform) {}
			virtual ~Component() {}

			virtual void Render(SDL_Renderer* renderer) {}
			virtual void Update() {}

			Transform* transform;
		};
	}
}