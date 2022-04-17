#include "Scene.h"

void RubtidDungeon::Scenes::Scene::Render(SDL_Renderer* renderer)
{
	ObjectManager::Instance()->Render(renderer);
}