#pragma once
#include <vector>

#include "Subscriber.h"

namespace RubtidDungeon {
	class Subject {
	public:
		Subject();

		void Subscribe(Subscriber* subscriber);
		void Unsubscribe(Subscriber* subscriber);
		void Emit(std::string eventName);
	private:
		std::vector<Subscriber*> mSubs;
	};
}