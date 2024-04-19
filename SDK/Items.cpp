#include "Items.h"

jclass CItems::GetItemClass() {
	return lc->GetClass("net.minecraft.item.Item");
}

jclass CItems::GetItemsClass() {
	return lc->GetClass("net.minecraft.init.Items");
}

CItems::CItems() {
	this->waterBucket = GetWaterBucketItem();
	this->paper = GetPaperItem();
}

jobject CItems::GetWaterBucketItem() {
	jfieldID waterBucketField = lc->env->GetStaticFieldID(this->GetItemsClass(), "water_bucket", "Lnet/minecraft/item/Item;");
	return lc->env->GetStaticObjectField(this->GetItemClass(), waterBucketField);;
}

jobject CItems::GetPaperItem() {
	jfieldID paperField = lc->env->GetStaticFieldID(this->GetItemsClass(), "paper", "Lnet/minecraft/item/Item;");
	return lc->env->GetStaticObjectField(this->GetItemClass(), paperField);
}


