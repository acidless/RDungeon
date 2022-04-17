#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "../Components/Component.h"
#include "../Utils/Subscriber.h"

namespace RubtidDungeon {
	namespace Graphics {
		class Texture : public Components::Component, public Subscriber {
		public:
			Texture(Transform* parent, SDL_Renderer* renderer, std::string path);
			~Texture();

			virtual operator bool() const {
				return mTexture;
			}

			virtual void Render(SDL_Renderer* renderer) override;
			virtual void OnEvent(std::string eventName) override;

			Texture* SetSize(int width, int height);
			Texture* SetPosition(int x, int y);
			SDL_Rect mSize;
		private:
			SDL_Texture* mTexture;
		};
	}
}