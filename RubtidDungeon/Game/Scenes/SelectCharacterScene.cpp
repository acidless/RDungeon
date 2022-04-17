#include "SelectCharacterScene.h"


RubtidDungeon::Scenes::SelectCharacterScene::SelectCharacterScene(SDL_Renderer* renderer) : Scene(renderer)
{
	auto* knight = new GameObject();
	knight->GetTransform().SetPosition(Vector2(200, 200));
	knight->AddComponent<Graphics::Texture>(renderer, "assets/images/knight.png").SetSize(38 * 3, 45 * 3);

	auto* rogue = new GameObject();
	rogue->GetTransform().SetPosition(Vector2(400, 200));
	rogue->AddComponent<Graphics::Texture>(renderer, "assets/images/rogue.png").SetSize(24 * 3, 44 * 3);
	rogue->AddComponent<Components::PlayerInput>();

	auto* mage = new GameObject();
	mage->GetTransform().SetPosition(Vector2(600, 200));
	mage->AddComponent<Graphics::Texture>(renderer, "assets/images/mage.png").SetSize(37 * 3, 44 * 3);

	auto font = Graphics::Text::Font("assets/fonts/SFPixelate.ttf", 24);
	auto* text = (new Graphics::Text::Text(renderer, font, "Select a character", { 0, 100 }, { 255, 255, 255 }))
		->SetAlign(Graphics::Text::TEXT_ALIGN::CENTER);
}
