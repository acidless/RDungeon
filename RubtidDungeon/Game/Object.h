#pragma once
#include <SDL.h>

namespace RubtidDungeon {
	class Object {
	public:
		virtual ~Object() {}
		virtual void Update() {}
		virtual void Render(SDL_Renderer* renderer) {}
	};
}