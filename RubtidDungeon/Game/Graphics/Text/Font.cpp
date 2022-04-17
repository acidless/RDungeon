#include "Font.h"

RubtidDungeon::Graphics::Text::Font::Font(std::string path, unsigned short fontSize) : mFont(TTF_OpenFont(path.c_str(), fontSize))
{
}

RubtidDungeon::Graphics::Text::Font::~Font()
{
	TTF_CloseFont(mFont);
}

TTF_Font* RubtidDungeon::Graphics::Text::Font::GetTTFFont()
{
	return mFont;
}
