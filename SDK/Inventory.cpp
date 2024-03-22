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

void CInventory::dropAllItems() {
	jmethodID getdropMethod = lc->env->GetMethodID(this->GetClass(), "dropAllItems", "()V");

	try {
		lc->env->CallVoidMethod(inventoryInstance, getdropMethod);
		printf("Dropped all items\n");
	}
	catch (const std::exception e) {
		printf("Exception occured!\n", e.what());
	}
}

void CInventory::armorItemInSlot(int index) { //yeye not working
	jmethodID getarmorItemInSlotMethod = lc->env->GetMethodID(this->GetClass(), "armorItemInSlot", "(I)Lnet/minecraft/item/ItemStack;");
	lc->env->CallVoidMethod(inventoryInstance, getarmorItemInSlotMethod);
}

void CInventory::checkArmor() {
	jfieldID armorSlotsField = lc->env->GetFieldID(this->GetClass(), "armorInventory", "[Lnet/minecraft/item/ItemStack;");
	jobjectArray armorInventoryObjArray = static_cast<jobjectArray>(lc->env->GetObjectField(inventoryInstance, armorSlotsField));

	jsize lenght = lc->env->GetArrayLength(armorInventoryObjArray);

	for (int i = 0; i < lenght; i++) {
		jobject itemStack = lc->env->GetObjectArrayElement(armorInventoryObjArray, i);
		jboolean isNull = lc->env->IsSameObject(itemStack, nullptr);

		if (isNull) {
			switch (i) {
			case 0:
				printf("No boots\n");
				break;
			case 1:
				printf("No leggings\n");
				break;
			case 2:
				printf("No chestplate\n");
				break;
			case 3:
				printf("No helmet\n");
				break;
			}
		}
		else {
			switch (i) {
			case 0:
				printf("You have boots\n");
				break;
			case 1:
				printf("You have leggings\n");
				break;
			case 2:
				printf("You have chestplate\n");
				break;
			case 3:
				printf("You have helmet\n");
				break;
			}
		}
		lc->env->DeleteLocalRef(itemStack);
	}

	lc->env->DeleteLocalRef(armorInventoryObjArray);
}
