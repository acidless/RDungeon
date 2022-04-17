#include "Window.h"
#include <memory>

SDL_Texture* texture;
RubtidDungeon::Scenes::Scene* scene = nullptr;

RubtidDungeon::Window::Window(std::string name, USHORT maxFrameRate) :
	mWindow(SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN)),
	mRenderer(SDL_CreateRenderer(mWindow, -1, 0)),
	mMaxFrameRate(maxFrameRate)
{
	TTF_Init();
	mActiveWindow = this;
	scene = new Scenes::SelectCharacterScene(mRenderer);
}

void RubtidDungeon::Window::HandleEvents()
{
	SDL_PollEvent(&SDL::event);
}

void RubtidDungeon::Window::Frame()
{
	SDL_SetRenderDrawColor(mRenderer, 31, 31, 31, 255);
	SDL_RenderClear(mRenderer);

	scene->Render(mRenderer);
	//ObjectManager::Instance()->Clear();

	SDL_RenderPresent(mRenderer);
	SDL_Delay(1000.0f / mMaxFrameRate);
}

SDL_Rect RubtidDungeon::Window::GetSize()
{
	return { 0, 0, 800, 600 };
}

RubtidDungeon::Window* RubtidDungeon::Window::GetActiveWindow()
{
	return mActiveWindow;
}

RubtidDungeon::Window* RubtidDungeon::Window::mActiveWindow = nullptr;