#pragma once
#include "../ObjectManager.h"

namespace RubtidDungeon {
	namespace Scenes {
		class Scene : public Object {
		public:
			virtual void Render(SDL_Renderer* renderer);
		protected:
			Scene(SDL_Renderer* renderer) {}
		};
	}
}