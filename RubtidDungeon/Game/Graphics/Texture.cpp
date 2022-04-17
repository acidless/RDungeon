#include "Texture.h"
#include <iostream>

RubtidDungeon::Graphics::Texture::Texture(Transform* parent, SDL_Renderer* renderer, std::string path) : Component(parent), mSize(SDL_Rect())
{
	auto* surface = IMG_Load(path.c_str());
	mTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if (transform) {
		auto pos = transform->GetPosition();
		SetPosition(pos.x, pos.y);

		transform->Subscribe(this);
	}
}

RubtidDungeon::Graphics::Texture::~Texture()
{
	SDL_DestroyTexture(mTexture);
}

void RubtidDungeon::Graphics::Texture::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, mTexture, NULL, SDL_RectEmpty(&mSize) ? NULL : &mSize);
}

void RubtidDungeon::Graphics::Texture::OnEvent(std::string eventName)
{
	if (eventName == "posChange") {
		auto pos = transform->GetPosition();
		SetPosition(pos.x, pos.y);
	}
}

RubtidDungeon::Graphics::Texture* RubtidDungeon::Graphics::Texture::SetSize(int width, int height)
{
	mSize.w = width;
	mSize.h = height;

	return this;
}

RubtidDungeon::Graphics::Texture* RubtidDungeon::Graphics::Texture::SetPosition(int x, int y)
{
	mSize.x = x;
	mSize.y = y;

	return this;
}
