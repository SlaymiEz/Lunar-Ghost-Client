#pragma once
#include "../Java.h"

class CInventory {
public:
	CInventory(jobject instance);
	jclass GetClass();

	void clear();
	void dropAllItems();
	void checkArmor();
	jobject GetInstance();
private:
	jobject inventoryInstance;
};