#pragma once
#include "Component.h"
#include "../SDL.h"

namespace RubtidDungeon {
	namespace Components {
		class PlayerInput : public Component {
		public:
			PlayerInput(Transform* transform);
			virtual void Update() override;
		private:
			int mSpeed;
		};
	}
}