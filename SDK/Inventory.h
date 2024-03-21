#pragma once
#include "../Java.h"

class CInventory {
public:
	CInventory(jobject instance);
	jclass GetClass();

	void clear();
	void armorItemInSlot(int index);
	void dropAllItems();
	void checkArmor();
private:
	jobject inventoryInstance;
};