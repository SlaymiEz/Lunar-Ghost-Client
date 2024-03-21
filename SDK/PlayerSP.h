#pragma once
#include "../Java.h"
#include "Inventory.h"

class CPlayerSP {
public:
	CPlayerSP(jobject instance);
	jclass GetEntityClass();
	jclass GetPlayerSPClass();
	jclass GetPlayerClass();

	CInventory GetLocalInventory();

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