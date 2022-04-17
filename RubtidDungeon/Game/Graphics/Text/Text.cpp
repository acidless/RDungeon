#include "Text.h"

RubtidDungeon::Graphics::Text::Text::Text(SDL_Renderer* renderer, Font& mFont, std::string text, SDL_Rect position, SDL_Color color)
{
	auto* font = mFont.GetTTFFont();

	if (font) {
		SDL_Surface* surfaceMessage =
			TTF_RenderText_Solid(mFont.GetTTFFont(), text.c_str(), color);

		mMessage = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

		mMessageRect.x = position.x;
		mMessageRect.y = position.y;
		mMessageRect.w = surfaceMessage->w;
		mMessageRect.h = surfaceMessage->h;

		SDL_FreeSurface(surfaceMessage);
		ObjectManager::Instance()->AddObject(this);
	}
}

RubtidDungeon::Graphics::Text::Text::~Text()
{
	SDL_DestroyTexture(mMessage);
}

void RubtidDungeon::Graphics::Text::Text::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, mMessage, NULL, &mMessageRect);
}

RubtidDungeon::Graphics::Text::Text* RubtidDungeon::Graphics::Text::Text::SetAlign(TEXT_ALIGN align)
{
	auto rect = Window::GetActiveWindow()->GetSize();

	switch (align) {
	case TEXT_ALIGN::CENTER:
		mMessageRect.x += rect.w / 2 - mMessageRect.w / 2;
		break;
	case TEXT_ALIGN::RIGHT:
		mMessageRect.x = rect.w - mMessageRect.x - mMessageRect.w;
		break;
	}

	return this;
}
