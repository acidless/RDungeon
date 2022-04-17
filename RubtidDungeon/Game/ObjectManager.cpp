#include "ObjectManager.h"

RubtidDungeon::ObjectManager::ObjectManager() {

}

RubtidDungeon::ObjectManager* RubtidDungeon::ObjectManager::Instance()
{
	if (!mInstance) {
		mInstance = new ObjectManager();
	}

	return mInstance;
}

void RubtidDungeon::ObjectManager::AddObject(Object* obj)
{
	mObjects.push_back(obj);
}

void RubtidDungeon::ObjectManager::Clear()
{
	mObjects.clear();
}

void RubtidDungeon::ObjectManager::Render(SDL_Renderer* renderer)
{
	for (auto& obj : mObjects) {
		obj->Update();
		obj->Render(renderer);
	}
}

RubtidDungeon::ObjectManager* RubtidDungeon::ObjectManager::mInstance = nullptr;
