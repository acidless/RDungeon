#pragma once
#include <string>

namespace RubtidDungeon {
	class Subscriber {
	public:
		virtual void OnEvent(std::string eventName) = 0;
	};
}