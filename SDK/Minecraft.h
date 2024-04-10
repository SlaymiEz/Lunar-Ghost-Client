#pragma once
#include "Player.h"
#include "World.h"
#include "PlayerController.h"
#include "Items.h"

class CMinecraft {
public:
	jclass GetClass();
	jobject GetInstance();

	CPlayer GetLocalPlayer();
	CWorld GetLocalWorld();
	CPlayerController GetLocalPlayerController();
protected:
	jobject renderManager;
};