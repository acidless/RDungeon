#pragma once
#include "Font.h"
#include <iostream>
#include "../../ObjectManager.h"
#include "../../Window.h"


namespace RubtidDungeon {
	namespace Graphics {
		namespace Text {
			enum class TEXT_ALIGN {
				LEFT,
				CENTER,
				RIGHT
			};

			class Text : public Object {
			public:
				Text(SDL_Renderer* renderer, Font& mFont, std::string text, SDL_Rect position = { 0, 0, 0, 0 }, SDL_Color color = { 0, 0, 0 });
				~Text();

				virtual void Render(SDL_Renderer* renderer);

				Text* SetAlign(TEXT_ALIGN align);

			private:
				SDL_Rect mMessageRect;
				SDL_Texture* mMessage;
			};
		}
	}
}