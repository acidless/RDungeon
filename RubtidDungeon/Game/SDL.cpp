#include "SDL.h"

RubtidDungeon::SDL* RubtidDungeon::SDL::Instance()
{
	if (!mInstance) {
		mInstance = new SDL();
	}

	return mInstance;
}

bool RubtidDungeon::SDL::Init()
{
	return SDL_Init(SDL_INIT_EVERYTHING) == 0;
}

RubtidDungeon::SDL* RubtidDungeon::SDL::mInstance = nullptr;
SDL_Event RubtidDungeon::SDL::event;
