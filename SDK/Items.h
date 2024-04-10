#pragma once
#include "../Java.h"

class CItems {
public:
	CItems();
	jobject waterBucket;
private:
	jobject GetWaterBucketItem();
	jclass GetItemsClass();
	jclass GetItemClass();
};