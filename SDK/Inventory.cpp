#include "Inventory.h"

CInventory::CInventory(jobject instance) {
	this->inventoryInstance = instance;
}

jclass CInventory::GetClass(){
	return lc->GetClass("net.minecraft.entity.player.InventoryPlayer");
}

void CInventory::clear() {
	jclass inventoryClass = lc->GetClass("net.minecraft.entity.player.InventoryPlayer");
	printf("Loaded the inventory class\n");
	jmethodID getclearMethod = lc->env->GetMethodID(inventoryClass, "clear", "()V");
	printf("Loaded the clear method\n");

	try {
		lc->env->CallVoidMethod(inventoryInstance, getclearMethod);
		printf("Inventory cleared \n");
	}
	catch (const std::exception e) {
		printf("Exception occured!\n", e.what());
	}
}