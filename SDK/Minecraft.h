#pragma once
#include "PlayerSP.h"
#include "Player.h"



class CMinecraft {
public:
	jclass GetClass();
	jobject GetInstance();

	CPlayerSP GetLocalPlayerSP();
	CPlayer GetLocalPlayer();

};