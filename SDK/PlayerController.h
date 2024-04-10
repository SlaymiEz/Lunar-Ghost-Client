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

	void sendUseItem(CPlayer* player, CWorld* world, jobject itemStack); // TO-DO : Add a third argument containing an itemstack
private:
	jobject playerControllerInstance;
};