#pragma once
#include <SDL.h>
#undef main

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include "Graphics/Texture.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_ttf.lib")

namespace RubtidDungeon {
	class SDL {
	public:
		static SDL* Instance();

		bool Init();

		static SDL_Event event;
	private:
		SDL() {}
		static SDL* mInstance;
	};
}
