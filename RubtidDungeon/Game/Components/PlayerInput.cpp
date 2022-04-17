#include "PlayerInput.h"

RubtidDungeon::Components::PlayerInput::PlayerInput(Transform* transform) : Component(transform), mSpeed(20)
{
}

void RubtidDungeon::Components::PlayerInput::Update()
{
	if (SDL::event.type == SDL_KEYDOWN) {
		switch (SDL::event.key.keysym.sym) {
		case SDLK_w:
			transform->SetVelocityY(Vector2::up.y * mSpeed);
			break;
		case SDLK_s:
			transform->SetVelocityY(Vector2::down.y * mSpeed);
			break;
		case SDLK_a:
			transform->SetVelocityX(Vector2::left.x * mSpeed);
			break;
		case SDLK_d:
			transform->SetVelocityX(Vector2::right.x * mSpeed);
			break;
		}
	}
	else if (SDL::event.type == SDL_KEYUP) {
		switch (SDL::event.key.keysym.sym) {
		case SDLK_w:
		case SDLK_s:
			transform->SetVelocityY(0);
			break;
		case SDLK_a:
		case SDLK_d:
			transform->SetVelocityX(0);
			break;
		}
		
	}
}