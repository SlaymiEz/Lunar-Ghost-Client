#pragma once
#include "../Java.h"

class CPlayerSP {
public:
	CPlayerSP(jobject instance);
	jclass GetEntityClass();
	jclass GetPlayerSPClass();
	jclass GetPlayerClass();

	void Cleanup();

	bool isSneaking();
	bool isBurning();

	float GetExperience(); // Not working

	int GetExperienceLvL(); // Not working

	double GetX(), GetY(), GetZ();

	void sendChatMessage(jstring message); // Not working

	void clear();
private:
	jobject playerInstance;
};