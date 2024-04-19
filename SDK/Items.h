#pragma once
#include "../Java.h"

class CItems {
public:
	CItems();
	jobject waterBucket;
	jobject paper;
private:
	jclass GetItemsClass();
	jclass GetItemClass();
	jobject GetWaterBucketItem();
	jobject GetPaperItem();
};