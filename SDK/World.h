#pragma once
#include "../Java.h"




class CWorld {
public:
	CWorld(jobject instance);
	jclass GetWorldClientClass();
	jobject GetInstance();

private:
	jobject worldInstance;
};
