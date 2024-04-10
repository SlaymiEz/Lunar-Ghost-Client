#pragma once
#include "../Java.h"
#include "Inventory.h"

//class CIChatComponent;

class CPlayer {
public:
	CPlayer(jobject instance);
	jclass GetEntityClass();
	jclass GetPlayerSPClass();
	jclass GetPlayerClass();
	jclass GetPlayerMPClass();
	jclass GetLivingBaseClass();

	jobject GetHeldItem();
	jobject GetHeldItemStack();

	CInventory GetLocalInventory();

	void Cleanup();
	
	void addExperience(int points);
	void addExperienceLevel(int level);
	void setMotion(double x, double y, double z);
	void setPitch(float pitch);

	bool isSneaking();
	bool isBurning();

	float GetExperience();
	float GetHealth();

	int GetExperienceLvL(); 
	int GetHurtResistantTime();

	double GetX(), GetY(), GetZ();
	double GetMotionX(), GetMotionY(), GetMotionZ();
	
	float GetYaw(), GetPitch();

	void sendChatMessage(const std::string &msg); // Working
	void chatLog(const std::string &msg);

	bool isHit();
private:
	jobject playerInstance;
};