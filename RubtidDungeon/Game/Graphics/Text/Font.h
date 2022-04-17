#pragma once
#include <string>
#include <SDL_ttf.h>

namespace RubtidDungeon {
	namespace Graphics {
		namespace Text {
			class Font {
			public:
				Font(std::string path, unsigned short fontSize);
				~Font();

				TTF_Font* GetTTFFont();
			private:
				TTF_Font* mFont;
			};
		}
	}
}