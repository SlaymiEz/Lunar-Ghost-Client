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

jclass CPlayerSP::GetPlayerMPClass() {
	return lc->GetClass("net.minecraft.entity.player.EntityPlayerMP");
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

double CPlayerSP::GetMotionX() {
	jfieldID motionX = lc->env->GetFieldID(this->GetEntityClass(), "motionX", "D");
	return lc->env->GetDoubleField(this->playerInstance, motionX);
}

double CPlayerSP::GetMotionY() {
	jfieldID motionY = lc->env->GetFieldID(this->GetEntityClass(), "motionY", "D");
	return lc->env->GetDoubleField(this->playerInstance, motionY);
}

double CPlayerSP::GetMotionZ() {
	jfieldID motionZ = lc->env->GetFieldID(this->GetEntityClass(), "motionZ", "D");
	return lc->env->GetDoubleField(this->playerInstance, motionZ);
}

void CPlayerSP::setMotion(double x, double y, double z) {
	jfieldID motionX = lc->env->GetFieldID(this->GetEntityClass(), "motionX", "D");
	jfieldID motionY = lc->env->GetFieldID(this->GetEntityClass(), "motionY", "D");
	jfieldID motionZ = lc->env->GetFieldID(this->GetEntityClass(), "motionZ", "D");

	lc->env->SetDoubleField(this->playerInstance, motionX, x);
	lc->env->SetDoubleField(this->playerInstance, motionY, y);
	lc->env->SetDoubleField(this->playerInstance, motionZ, z);
}

// ---------------------- 

int CPlayerSP::GetExperienceLvL() {
	jfieldID xpLvL = lc->env->GetFieldID(this->GetPlayerClass(), "experienceLevel", "I");
	return lc->env->GetIntField(this->playerInstance, xpLvL);
}

int CPlayerSP::GetHurtResistantTime() {
	jfieldID hurtResistantTime = lc->env->GetFieldID(this->GetEntityClass(), "hurtResistantTime", "I");
	return lc->env->GetIntField(this->playerInstance, hurtResistantTime);
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

void CPlayerSP::addExperience(int points) {
	jmethodID addExperience = lc->env->GetMethodID(this->GetPlayerClass(), "addExperience", "(I)V");
	lc->env->CallVoidMethod(playerInstance, addExperience, points);
}

void CPlayerSP::addExperienceLevel(int level) {
	jmethodID addExperienceLevel = lc->env->GetMethodID(this->GetPlayerClass(), "addExperienceLevel", "(I)V");
	lc->env->CallVoidMethod(playerInstance, addExperienceLevel, level);
}

void CPlayerSP::sendChatMessage(const std::string &msg) {
	jmethodID sendChatMessage = lc->env->GetMethodID(this->GetPlayerSPClass(), "sendChatMessage", "(Ljava/lang/String;)V");

	jstring msgString = lc->env->NewStringUTF(msg.c_str());
	lc->env->CallVoidMethod(playerInstance, sendChatMessage, msgString);
}

void CPlayerSP::chatLog(const std::string& msg) {
	jmethodID addChatMessage = lc->env->GetMethodID(this->GetPlayerSPClass(), "addChatMessage", "(Lnet/minecraft/util/IChatComponent;)V");
	jclass chatComponentTextClass = lc->GetClass("net.minecraft.util.ChatComponentText");
	jmethodID chatConstructorID = lc->env->GetMethodID(chatComponentTextClass, "<init>", "(Ljava/lang/String;)V");
	jobject chatComponentObj = lc->env->NewObject(chatComponentTextClass, chatConstructorID, lc->env->NewStringUTF(msg.c_str()));
	lc->env->CallVoidMethod(playerInstance, addChatMessage, chatComponentObj);
}

bool CPlayerSP::isHit() { // Not working
	if (this->GetHurtResistantTime() == 20) {
		return true;
	}
	else {
		return false;
	}
}