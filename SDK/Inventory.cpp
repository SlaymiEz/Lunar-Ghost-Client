#include "Inventory.h"

CInventory::CInventory(jobject instance) {
	this->inventoryInstance = instance;
}

jclass CInventory::GetClass(){
	return lc->GetClass("net.minecraft.entity.player.InventoryPlayer");
}

void CInventory::clear() {
	jmethodID getclearMethod = lc->env->GetMethodID(this->GetClass(), "clear", "()V");

	try {
		lc->env->CallVoidMethod(inventoryInstance, getclearMethod);
		printf("Inventory cleared \n");
	}
	catch (const std::exception e) {
		printf("Exception occured!\n", e.what());
	}
}

void CInventory::armorItemInSlot(int index) { //yeye not working
	jmethodID getarmorItemInSlotMethod = lc->env->GetMethodID(this->GetClass(), "armorItemInSlot", "(I)Lnet/minecraft/item/ItemStack;");
	lc->env->CallVoidMethod(inventoryInstance, getarmorItemInSlotMethod);
}