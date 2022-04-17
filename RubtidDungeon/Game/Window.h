#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "SDL.h"

#include "Scenes/SelectCharacterScene.h"
#include "ObjectManager.h"

namespace RubtidDungeon {
	class Window {
	public:
		Window(std::string name, USHORT maxFrameRate = 60);

		void HandleEvents();
		void Frame();

		SDL_Rect GetSize();

		static Window* GetActiveWindow();
	private:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
		USHORT mMaxFrameRate;

		static Window* mActiveWindow;
	};
}