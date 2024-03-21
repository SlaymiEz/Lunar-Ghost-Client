#include "Inventory.h"

jclass CInventory::GetClass{
	return lc->GetClass("net.minecraft.entity.player.InventoryPlayer");
}