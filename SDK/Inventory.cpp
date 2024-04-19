#include "Inventory.h"
#include "Player.h"
#include "Minecraft.h"

CInventory::CInventory(jobject instance) {
	this->inventoryInstance = instance;
}

jclass CInventory::GetClass() {
	return lc->GetClass("net.minecraft.entity.player.InventoryPlayer");
}

jobject CInventory::GetInstance() {
	return this->inventoryInstance;
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

void CInventory::checkArmor() {
	std::unique_ptr<CMinecraft> minecraft = std::make_unique<CMinecraft>();
	std::unique_ptr<CPlayer> player = std::make_unique<CPlayer>(minecraft->GetLocalPlayer());
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
				//player->chatLog("No boots");
				break;
			case 1:
				printf("No leggings\n");
				//player->chatLog("No leggings");
				break;
			case 2:
				printf("No chestplate\n");
				//player->chatLog("No chestplate");
				break;
			case 3:
				printf("No helmet\n");
				//player->chatLog("No helmet");
				break;
			}
		}
		else {
			switch (i) {
			case 0:
				//player->chatLog("You have boots");
				break;
			case 1:
				//player->chatLog("You have leggigs");
				break;
			case 2:
				//player->chatLog("You have chestplate");
				break;
			case 3:
				//player->chatLog("You have helmet");
				break;
			}
		}
		lc->env->DeleteLocalRef(itemStack);
	}
	lc->env->DeleteLocalRef(armorInventoryObjArray);
}

int CInventory::GetCurrentSlot() {
	jfieldID currentItem = lc->env->GetFieldID(this->GetClass(), "currentItem", "I");
	return lc->env->GetIntField(this->GetInstance(), currentItem) + 1;
}

int CInventory::GetWaterBucketSlot() {
	jclass itemStackClass = lc->GetClass("net.minecraft.item.ItemStack");
	jmethodID itemStackGetItemMethod = lc->env->GetMethodID(itemStackClass, "getItem", "()Lnet/minecraft/item/Item;"); // Loading the getItem method
	
	jfieldID hotbarSlotsField = lc->env->GetFieldID(this->GetClass(), "mainInventory", "[Lnet/minecraft/item/ItemStack;");
	jobjectArray mainInvObjArray = static_cast<jobjectArray>(lc->env->GetObjectField(inventoryInstance, hotbarSlotsField)); // Loading the mainInventory array
	
	jclass itemsClass = lc->GetClass("net.minecraft.init.Items");
	jclass itemClass = lc->GetClass("net.minecraft.item.Item"); // Loading the 2 classes we'll need for later

	jfieldID waterBucketField = lc->env->GetStaticFieldID(itemsClass, "water_bucket", "Lnet/minecraft/item/Item;");
	jobject waterBucketObject = lc->env->GetStaticObjectField(itemClass, waterBucketField); // Loading the water_bucket object

	int waterSlot = 0;
	for (int i = 0; i <= 8; i++) {
		jobject itemStack = lc->env->GetObjectArrayElement(mainInvObjArray, i); // Loading the itemStack present the mainInventory[i]
		jobject item = lc->env->CallObjectMethod(itemStack, itemStackGetItemMethod); // Uses the getItem method on the itemStack to return an item
		jboolean isSameObject = lc->env->IsSameObject(item, waterBucketObject); // Compares the water_bucket item and the item
		if (isSameObject == true) {
			int localWaterSlot = i + 1;
			waterSlot = localWaterSlot;
		}
		lc->env->DeleteLocalRef(itemStack);
	}
	lc->env->DeleteLocalRef(mainInvObjArray);
	lc->env->DeleteLocalRef(waterBucketObject);
	return waterSlot;
}

int CInventory::GetTotalPots() { // Working
	jclass itemStackClass = lc->GetClass("net.minecraft.item.ItemStack");
	jmethodID itemStackGetItemMethod = lc->env->GetMethodID(itemStackClass, "getItem", "()Lnet/minecraft/item/Item;"); // Loading the getItem method
	jmethodID itemStackGetMetadataMethod = lc->env->GetMethodID(itemStackClass, "getMetadata", "()I"); // Loading the getMetadata method
	
	jfieldID inventoryField = lc->env->GetFieldID(this->GetClass(), "mainInventory", "[Lnet/minecraft/item/ItemStack;");
	jobjectArray mainInvObjArray = static_cast<jobjectArray>(lc->env->GetObjectField(inventoryInstance, inventoryField)); // Loading the mainInventory array
	
	int totalPots = 0;
	for (int i = 0; i < 35; i++) {
		jobject itemStack = lc->env->GetObjectArrayElement(mainInvObjArray, i); // Loads the itemStack for each slot in the inventory
		jboolean isNullObject = lc->env->IsSameObject(itemStack, nullptr); // Checks if it's not null
		if (!isNullObject) {
			if (lc->env->CallIntMethod(itemStack, itemStackGetMetadataMethod) == 16421) { // Verifies if it's the good item through metadata (Splash potion of Health 2)
				totalPots++;
			}
		}
		lc->env->DeleteLocalRef(itemStack);
	}
	lc->env->DeleteLocalRef(mainInvObjArray);
	return totalPots;
}

