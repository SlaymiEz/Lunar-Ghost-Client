#pragma once
#include "PlayerSP.h"
#include "World.h"


class CMinecraft {
public:
	jclass GetClass();
	jobject GetInstance();

	CPlayerSP GetLocalPlayerSP();
	CWorld GetLocalWorld();
protected:
	jobject renderManager;
};