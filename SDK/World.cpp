#include "World.h"

CWorld::CWorld(jobject instance) {
	this->worldInstance = instance;
}

jclass CWorld::GetWorldClientClass() {
	return lc->GetClass("net.minecraft.client.multiplayer.WorldClient");
}

jobject CWorld::GetInstance() {
	return this->worldInstance;
}