#pragma once
#include "../Java.h"

class CItems {
public:
	CItems();
	jobject waterBucket;
private:
	jclass GetItemsClass();
	jclass GetItemClass();
	jobject GetWaterBucketItem();
};