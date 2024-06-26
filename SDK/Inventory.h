#pragma once
#include "../Java.h"

class CInventory {
public:
	CInventory(jobject instance);
	jclass GetClass();

	void clear();
	void dropAllItems();
	void checkArmor();
	
	int GetCurrentSlot();
	int GetWaterBucketSlot();
	int GetTotalPots();
	jobject GetInstance();
private:
	jobject inventoryInstance;
};