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

void CPlayerController::sendUseItem(CPlayer* player, CWorld* world, jobject itemStack) {

}

bool CPlayerController::isSpeactator() {
	jmethodID isSpectatorMode = lc->env->GetMethodID(this->GetMPClass(), "isSpectatorMode", "()Z");
	return lc->env->CallBooleanMethod(this->playerControllerInstance, isSpectatorMode);
}