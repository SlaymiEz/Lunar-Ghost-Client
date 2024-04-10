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