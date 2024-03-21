#include "PlayerSP.h"
#include "Inventory.h"

CPlayerSP::CPlayerSP(jobject instance) {
	this->playerInstance = instance;
}

void CPlayerSP::Cleanup() {
	lc->env->DeleteLocalRef(this->playerInstance);
}

jclass CPlayerSP::GetEntityClass() {
	return lc->GetClass("net.minecraft.entity.Entity");
}

jclass CPlayerSP::GetPlayerSPClass() {
	return lc->GetClass("net.minecraft.client.entity.EntityPlayerSP");
}

jclass CPlayerSP::GetPlayerClass() {
	return lc->GetClass("net.minecraft.entity.player.EntityPlayer");
}

// --------------------

bool CPlayerSP::isSneaking() {
	jmethodID isSneaking = lc->env->GetMethodID(this->GetEntityClass(), "isSneaking", "()Z");

	bool rtrn = lc->env->CallBooleanMethod(this->playerInstance, isSneaking);

	return rtrn;
}

bool CPlayerSP::isBurning() {
	jmethodID isBurning = lc->env->GetMethodID(this->GetEntityClass(), "isBurning", "()Z");

	bool rtrn = lc->env->CallBooleanMethod(this->playerInstance, isBurning);

	return rtrn;
}

void CPlayerSP::sendChatMessage(jstring message) { // Not working
	jmethodID sendChatMessage = lc->env->GetMethodID(this->GetEntityClass(), "sendChatMessage", "(Ljava/lang/String;)V");
	lc->env->CallVoidMethod(this->playerInstance, sendChatMessage);
}

// ---------------------

double CPlayerSP::GetX() {
	jfieldID x = lc->env->GetFieldID(this->GetEntityClass(), "posX", "D");
	return lc->env->GetDoubleField(this->playerInstance, x);
}

double CPlayerSP::GetY() {
	jfieldID y = lc->env->GetFieldID(this->GetEntityClass(), "posY", "D");
	return lc->env->GetDoubleField(this->playerInstance, y);
}

double CPlayerSP::GetZ() {
	jfieldID z = lc->env->GetFieldID(this->GetEntityClass(), "posZ", "D");
	return lc->env->GetDoubleField(this->playerInstance, z);
}

// ---------------------- 

int CPlayerSP::GetExperienceLvL() {
	jfieldID xpLvL = lc->env->GetFieldID(this->GetPlayerClass(), "experienceLevel", "I");
	return lc->env->GetIntField(this->playerInstance, xpLvL);
}

float CPlayerSP::GetExperience() {
	jfieldID experience = lc->env->GetFieldID(this->GetPlayerClass(), "experience", "F");
	return lc->env->GetFloatField(this->playerInstance, experience);
}

// --------------------

CInventory CPlayerSP::GetLocalInventory() {
	jfieldID playerInventoryField = lc->env->GetFieldID(this->GetPlayerClass(), "inventory", "Lnet/minecraft/entity/player/InventoryPlayer;");
	jobject playerInventoryObj = lc->env->GetObjectField(playerInstance, playerInventoryField);

	return CInventory(playerInventoryObj);
}