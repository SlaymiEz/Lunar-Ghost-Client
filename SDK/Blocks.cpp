#include "Blocks.h"

jclass CBlocks::GetBlocksClass() {
	return lc->GetClass("net.minecraft.init.Blocks");
}

jclass CBlocks::GetBlockClass() {
	return lc->GetClass("net.minecraft.block.Block");
}

CBlocks::CBlocks() {
	this->stone = GetStoneBlock();
	this->barrier = GetBarrierBlock();
}

jobject CBlocks::GetStoneBlock() {
	jfieldID stoneBlockID = lc->env->GetStaticFieldID(this->GetBlocksClass(), "stone", "Lnet/minecraft/block/Block;");
	return lc->env->GetStaticObjectField(this->GetBlockClass(), stoneBlockID);
}

jobject CBlocks::GetBarrierBlock() {
	jfieldID barrierBlockID = lc->env->GetStaticFieldID(this->GetBlocksClass(), "barrier", "Lnet/minecraft/block/Block;");
	return lc->env->GetStaticObjectField(this->GetBlockClass(), barrierBlockID);
}