#include "World.h"

CWorld::CWorld(jobject instance) {
	this->worldInstance = instance;
}

jclass CWorld::GetWorldClass() {
	return lc->GetClass("net.minecraft.world.World");
}

jclass CWorld::GetWorldClientClass() {
	return lc->GetClass("net.minecraft.client.multiplayer.WorldClient");
}

jobject CWorld::GetInstance() {
	return this->worldInstance;
}

bool CWorld::setBlockState(int x, int y, int z, jobject block) {
	jclass worldClass = this->GetWorldClass();
	jclass blockPosClass = lc->GetClass("net.minecraft.util.BlockPos");
	jclass blockClass = lc->GetClass("net.minecraft.block.Block");
	
	jmethodID setBlockStateID = lc->env->GetMethodID(worldClass, "setBlockState", "(Lnet/minecraft/util/BlockPos;Lnet/minecraft/block/state/IBlockState;)Z");
	jmethodID blockConstructorID = lc->env->GetMethodID(blockPosClass, "<init>", "(III)V");

	jobject blockPosObj = lc->env->NewObject(blockPosClass, blockConstructorID, x, y, z);

	jmethodID getDefaultState = lc->env->GetMethodID(blockClass, "getDefaultState", "()Lnet/minecraft/block/state/IBlockState;");
	
	jobject state = lc->env->CallObjectMethod(block, getDefaultState);

	return lc->env->CallBooleanMethod(worldInstance, setBlockStateID, blockPosObj, state);
}