#pragma once
#include <SDL.h>
#include <typeinfo>
#include <map>
#include <memory>

#include "Utils/Vector2.h"
#include "Graphics/Texture.h"
#include "Transform.h"
#include "ObjectManager.h"

namespace RubtidDungeon {
	class GameObject : public Object {
	public:
		GameObject();
		GameObject(Vector2 pos);

		template <typename T, class... Args>
		T& AddComponent(Args&&... args) {
			T* obj = new T(&mTransform, std::forward<Args>(args)...);
			obj->transform = &mTransform;

			auto pair = mComponents.insert(std::pair<std::string, std::unique_ptr<Components::Component>>(typeid(T).name(), std::unique_ptr<T>(obj)));
			return reinterpret_cast<T&>(*pair.first->second.get());
		}

		template <class T>
		T& GetComponent() {
			auto result = mComponents.find(typeid(T).name());
			if (result != mComponents.end()) {
				return reinterpret_cast<T&>(*result->second.get());
			}

			return nullptr;
		}

		template <class T>
		void DestroyComponent() {
			mComponents.erase(typeid(T).name());
		}

		virtual void Render(SDL_Renderer* renderer) override;
		virtual void Update() override;

		Transform& GetTransform();
	private:
		Transform mTransform;
		std::map<std::string, std::unique_ptr<Components::Component>> mComponents;
	};
}