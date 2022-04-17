#include "Subject.h"

RubtidDungeon::Subject::Subject() : mSubs(std::vector<Subscriber*>())
{

}

void RubtidDungeon::Subject::Subscribe(Subscriber* subscriber)
{
	mSubs.push_back(subscriber);
}

void RubtidDungeon::Subject::Unsubscribe(Subscriber* subscriber)
{
	for (auto iter = mSubs.begin(); iter < mSubs.end(); iter++) {
		if (*iter == subscriber) {
			mSubs.erase(iter);
		}
	}
}

void RubtidDungeon::Subject::Emit(std::string eventName)
{
	for (auto& sub : mSubs) {
		sub->OnEvent(eventName);
	}
}
