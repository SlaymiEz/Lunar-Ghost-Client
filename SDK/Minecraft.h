#pragma once
#include "Player.h"
#include "World.h"
#include "PlayerController.h"
#include "Items.h"
#include "Blocks.h"
#include "EnumFacing.h"
#include "EnumChatFormatting.h"

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