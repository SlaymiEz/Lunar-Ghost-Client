#pragma once
#include "../Java.h"

class CItemStack;

class CPlayerController {
public:
	CPlayerController(jobject instance);
	jclass GetMPClass();
	jobject GetInstance();

	//void sendUseItem(CPlayerSP player, CWorld world); // TO-DO : Add a third argument containing an itemstack
private:
	jobject playerControllerInstance;
};