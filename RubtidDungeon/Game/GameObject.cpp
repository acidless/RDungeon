#include "GameObject.h"

RubtidDungeon::GameObject::GameObject() : GameObject(Vector2(0, 0))
{
}

RubtidDungeon::GameObject::GameObject(Vector2 pos) : mTransform(Transform()), mComponents(std::map<std::string, std::unique_ptr<Components::Component>>())
{
	mTransform.SetPosition(pos);
	ObjectManager::Instance()->AddObject(this);
}

void RubtidDungeon::GameObject::Render(SDL_Renderer* renderer)
{
	for (auto& c : mComponents) {
		c.second->Render(renderer);
	}
}

void RubtidDungeon::GameObject::Update()
{
	mTransform.Update();
	for (auto& c : mComponents) {
		c.second->Update();
	}
}

RubtidDungeon::Transform& RubtidDungeon::GameObject::GetTransform()
{
	return mTransform;
}
