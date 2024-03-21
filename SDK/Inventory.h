#pragma once

class CInventory {
public:
	CInventory(jobject instance);

	jclass GetClass();
private:
	jobject inventoryInstance;
};