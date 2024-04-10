#pragma once
#include "../Java.h"

class CItems {
public:
	CItems();
	jclass GetItemsClass();
	jclass GetItemClass();
	jobject GetWaterBucketItem();
	jobject waterBucket;
};