#pragma once
#include "../Java.h"

class CPlayer {
public:
	CPlayer(jobject instance);
	jclass GetClass();

	void Cleanup();

	void clear();
private:
	jobject playerInstance;
};