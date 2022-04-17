#pragma once
#include <list>
#include "Object.h"

namespace RubtidDungeon {
	class ObjectManager {
	public:
		static ObjectManager* Instance();

		void AddObject(Object* obj);
		void Clear();
		void Render(SDL_Renderer* renderer);
	private:
		ObjectManager();
		std::list<Object*> mObjects;

		static ObjectManager* mInstance;
	};
}