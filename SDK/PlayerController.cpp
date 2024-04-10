#include "PlayerController.h"

CPlayerController::CPlayerController(jobject instance) {
	this->playerControllerInstance = instance;
}

jclass CPlayerController::GetMPClass() {
	return lc->GetClass("net.minecraft.client.multiplayer.PlayerControllerMP");
}

jobject CPlayerController::GetInstance() {
	return this->playerControllerInstance;
}

bool CPlayerController::sendUseItem(CPlayer player, CWorld world, jobject itemStack) {
	jmethodID sendUseItem = lc->env->GetMethodID(this->GetMPClass(), "sendUseItem", "(Lnet/minecraft/entity/player/EntityPlayer;Lnet/minecraft/world/World;Lnet/minecraft/item/ItemStack;)Z");
	std::cout << "loaded the sendUseItem method" << std::endl;
	return lc->env->CallBooleanMethod(this->playerControllerInstance, sendUseItem, player, world, itemStack);
}

bool CPlayerController::isSpectator() {
	jmethodID isSpectatorMode = lc->env->GetMethodID(this->GetMPClass(), "isSpectatorMode", "()Z");
	return lc->env->CallBooleanMethod(this->playerControllerInstance, isSpectatorMode);
}