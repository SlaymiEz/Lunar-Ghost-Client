#pragma once
#include "../Java.h"

class CBlocks {
public:
	CBlocks();
	jobject stone;
	jobject barrier;
	jobject glass;
private:
	jclass GetBlocksClass();
	jclass GetBlockClass();
	jobject GetStoneBlock();
	jobject GetBarrierBlock();
	jobject GetGlassBlock();
};