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

	float GetExperience();

	int GetExperienceLvL(); 

	double GetX(), GetY(), GetZ();

	void sendChatMessage(jstring message); // Not working

private:
	jobject playerInstance;
};