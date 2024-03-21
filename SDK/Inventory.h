#pragma once
#include "../Java.h"

class CInventory {
public:
	CInventory(jobject instance);
	jclass GetClass();

	void clear();
private:
	jobject inventoryInstance;
};