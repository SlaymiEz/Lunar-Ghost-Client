#pragma once
#include "PlayerSP.h"
#include "World.h"
#include "PlayerController.h"

class CMinecraft {
public:
	jclass GetClass();
	jobject GetInstance();

	CPlayerSP GetLocalPlayerSP();
	CWorld GetLocalWorld();
	CPlayerController GetLocalPlayerController();
protected:
	jobject renderManager;
};