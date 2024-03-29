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
	void setMotion(double x, double y, double z);

	bool isSneaking();
	bool isBurning();

	float GetExperience();

	int GetExperienceLvL(); 
	int GetHurtResistantTime();

	double GetX(), GetY(), GetZ();
	double GetMotionX(), GetMotionY(), GetMotionZ();

	void sendChatMessage(const std::string &msg); // Working
	void chatLog(const std::string &msg);

	bool isHit();

private:
	jobject playerInstance;
};