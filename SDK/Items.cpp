#include "Items.h"

jclass CItems::GetItemClass() {
	return lc->GetClass("net.minecraft.item.Item");
}

jclass CItems::GetItemsClass() {
	return lc->GetClass("net.minecraft.init.Items");
}

CItems::CItems() {
	this->waterBucket = GetWaterBucketItem();
}

jobject CItems::GetWaterBucketItem() {
	jfieldID waterBucketField = lc->env->GetStaticFieldID(this->GetItemsClass(), "water_bucket", "Lnet/minecraft/item/Item;");
	/*jobject waterBucket = lc->env->GetStaticObjectField(this->GetItemClass(), waterBucketField);
	return waterBucket;*/
	return lc->env->GetStaticObjectField(this->GetItemClass(), waterBucketField);;
}

