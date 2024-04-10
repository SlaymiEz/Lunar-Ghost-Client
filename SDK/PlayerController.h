#pragma once
#include "../Java.h"
#include "Player.h"
#include "World.h"

class CItemStack;

class CPlayerController {
public:
	CPlayerController(jobject instance);
	jclass GetMPClass();
	jobject GetInstance();
	
	bool isSpectator();

	bool sendUseItem(CPlayer player, CWorld world, jobject itemStack);
private:
	jobject playerControllerInstance;
};