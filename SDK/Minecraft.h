#pragma once
#include "PlayerSP.h"



class CMinecraft {
public:
	jclass GetClass();
	jobject GetInstance();

	CPlayerSP GetLocalPlayerSP();
};