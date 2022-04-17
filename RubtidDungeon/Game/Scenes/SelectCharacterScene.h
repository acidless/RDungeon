#pragma once
#include "Scene.h"

#include "../Graphics/Text/Font.h"
#include "../Graphics/Texture.h"
#include "../Graphics/Text/Text.h"
#include "../GameObject.h"
#include "../Components/PlayerInput.h"

namespace RubtidDungeon {
	namespace Scenes {
		class SelectCharacterScene : public Scene {
		public:
			SelectCharacterScene(SDL_Renderer* renderer);
		};
	}
}