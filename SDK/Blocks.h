#pragma once
#include "../Java.h"

class CBlocks {
public:
	CBlocks();
	jobject stone;
private:
	jclass GetBlocksClass();
	jclass GetBlockClass();
	jobject GetStoneBlock();
};