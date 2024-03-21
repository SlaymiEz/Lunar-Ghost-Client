#pragma once
#include "PlayerSP.h"
#include "Player.h"
#include "Inventory.h"


class CMinecraft {
public:
	jclass GetClass();
	jobject GetInstance();

	CPlayerSP GetLocalPlayerSP();
	CPlayer GetLocalPlayer();

	CInventory GetLocalInventory();
};