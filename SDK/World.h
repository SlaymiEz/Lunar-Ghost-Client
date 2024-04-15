#pragma once
#include "../Java.h"




class CWorld {
public:
	CWorld(jobject instance);
	jclass GetWorldClientClass();
	jclass GetWorldClass();
	jobject GetInstance();

	bool setBlockState(int x, int y, int z, jobject block);

	void placeBarrierAt(jobject world, int x, int y, int z);

private:
	jobject worldInstance;
};
