#pragma once
#include "../Java.h"
#include "Inventory.h"

class CIChatComponent;

class CPlayerSP {
public:
	CPlayerSP(jobject instance);
	jclass GetEntityClass();
	jclass GetPlayerSPClass();
	jclass GetPlayerClass();
	jclass GetPlayerMPClass();

	CInventory GetLocalInventory();

	void Cleanup();
	
	void addExperience(int points);
	void addExperienceLevel(int level);

	bool isSneaking();
	bool isBurning();

	float GetExperience();

	int GetExperienceLvL(); 

	double GetX(), GetY(), GetZ();

	void sendChatMessage(const std::string &msg); // Working
	void chatLog(const std::string &msg);

private:
	jobject playerInstance;
};