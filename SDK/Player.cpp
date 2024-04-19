#include "Player.h"
#include "Inventory.h"


CPlayer::CPlayer(jobject instance) {
	this->playerInstance = instance;
}

void CPlayer::Cleanup() {
	lc->env->DeleteLocalRef(this->playerInstance);
}

jclass CPlayer::GetEntityClass() {
	return lc->GetClass("net.minecraft.entity.Entity");
}

jclass CPlayer::GetPlayerSPClass() {
	return lc->GetClass("net.minecraft.client.entity.EntityPlayerSP");
}

jclass CPlayer::GetPlayerClass() {
	return lc->GetClass("net.minecraft.entity.player.EntityPlayer");
}

jclass CPlayer::GetPlayerMPClass() {
	return lc->GetClass("net.minecraft.entity.player.EntityPlayerMP");
}

jclass CPlayer::GetLivingBaseClass() {
	return lc->GetClass("net.minecraft.entity.EntityLivingBase");
}

// --------------------

bool CPlayer::isSneaking() {
	jmethodID isSneaking = lc->env->GetMethodID(this->GetEntityClass(), "isSneaking", "()Z");

	bool rtrn = lc->env->CallBooleanMethod(this->playerInstance, isSneaking);

	return rtrn;
}

bool CPlayer::isBurning() {
	jmethodID isBurning = lc->env->GetMethodID(this->GetEntityClass(), "isBurning", "()Z");

	bool rtrn = lc->env->CallBooleanMethod(this->playerInstance, isBurning);

	return rtrn;
}

// ---------------------

double CPlayer::GetX() {
	jfieldID x = lc->env->GetFieldID(this->GetEntityClass(), "posX", "D");
	return lc->env->GetDoubleField(this->playerInstance, x);
}

double CPlayer::GetY() {
	jfieldID y = lc->env->GetFieldID(this->GetEntityClass(), "posY", "D");
	return lc->env->GetDoubleField(this->playerInstance, y);
}

double CPlayer::GetZ() {
	jfieldID z = lc->env->GetFieldID(this->GetEntityClass(), "posZ", "D");
	return lc->env->GetDoubleField(this->playerInstance, z);
}

double CPlayer::GetMotionX() {
	jfieldID motionX = lc->env->GetFieldID(this->GetEntityClass(), "motionX", "D");
	return lc->env->GetDoubleField(this->playerInstance, motionX);
}

double CPlayer::GetMotionY() {
	jfieldID motionY = lc->env->GetFieldID(this->GetEntityClass(), "motionY", "D");
	return lc->env->GetDoubleField(this->playerInstance, motionY);
}

double CPlayer::GetMotionZ() {
	jfieldID motionZ = lc->env->GetFieldID(this->GetEntityClass(), "motionZ", "D");
	return lc->env->GetDoubleField(this->playerInstance, motionZ);
}

void CPlayer::setMotion(double x, double y, double z) {
	jfieldID motionX = lc->env->GetFieldID(this->GetEntityClass(), "motionX", "D");
	jfieldID motionY = lc->env->GetFieldID(this->GetEntityClass(), "motionY", "D");
	jfieldID motionZ = lc->env->GetFieldID(this->GetEntityClass(), "motionZ", "D");

	lc->env->SetDoubleField(this->playerInstance, motionX, x);
	lc->env->SetDoubleField(this->playerInstance, motionY, y);
	lc->env->SetDoubleField(this->playerInstance, motionZ, z);
}

// ---------------------- 

int CPlayer::GetExperienceLvL() {
	jfieldID xpLvL = lc->env->GetFieldID(this->GetPlayerClass(), "experienceLevel", "I");
	return lc->env->GetIntField(this->playerInstance, xpLvL);
}

int CPlayer::GetHurtResistantTime() {
	jfieldID hurtResistantTime = lc->env->GetFieldID(this->GetEntityClass(), "hurtResistantTime", "I");
	return lc->env->GetIntField(this->playerInstance, hurtResistantTime);
}

float CPlayer::GetExperience() {
	jfieldID experience = lc->env->GetFieldID(this->GetPlayerClass(), "experience", "F");
	return lc->env->GetFloatField(this->playerInstance, experience);
}

// --------------------

CInventory CPlayer::GetLocalInventory() {
	jfieldID playerInventoryField = lc->env->GetFieldID(this->GetPlayerClass(), "inventory", "Lnet/minecraft/entity/player/InventoryPlayer;");
	jobject playerInventoryObj = lc->env->GetObjectField(playerInstance, playerInventoryField);

	return CInventory(playerInventoryObj);
}

void CPlayer::addExperience(int points) {
	jmethodID addExperience = lc->env->GetMethodID(this->GetPlayerClass(), "addExperience", "(I)V");
	lc->env->CallVoidMethod(playerInstance, addExperience, points);
}

void CPlayer::addExperienceLevel(int level) {
	jmethodID addExperienceLevel = lc->env->GetMethodID(this->GetPlayerClass(), "addExperienceLevel", "(I)V");
	lc->env->CallVoidMethod(playerInstance, addExperienceLevel, level);
}

void CPlayer::sendChatMessage(const std::string &msg) {
	jmethodID sendChatMessage = lc->env->GetMethodID(this->GetPlayerSPClass(), "sendChatMessage", "(Ljava/lang/String;)V");

	jstring msgString = lc->env->NewStringUTF(msg.c_str());
	lc->env->CallVoidMethod(playerInstance, sendChatMessage, msgString);
}

/*void CPlayer::chatLog(jobject color, const std::string& msg) {
	jmethodID addChatMessage = lc->env->GetMethodID(this->GetPlayerSPClass(), "addChatMessage", "(Lnet/minecraft/util/IChatComponent;)V");
	jclass chatComponentTextClass = lc->GetClass("net.minecraft.util.ChatComponentText");
	jmethodID chatConstructorID = lc->env->GetMethodID(chatComponentTextClass, "<init>", "(Ljava/lang/String;)V");
	jobject chatComponentObj = lc->env->NewObject(chatComponentTextClass, chatConstructorID, color, lc->env->NewStringUTF(msg.c_str()));
	lc->env->CallVoidMethod(playerInstance, addChatMessage, chatComponentObj);
}*/

bool CPlayer::isHit() { // Not working
	if (this->GetHurtResistantTime() == 20) {
		return true;
	}
	else {
		return false;
	}
}

// --------------------

float CPlayer::GetYaw() {
	jfieldID yaw = lc->env->GetFieldID(this->GetEntityClass(), "rotationYaw", "F");
	return lc->env->GetFloatField(playerInstance, yaw);
}

float CPlayer::GetPitch() {
	jfieldID pitch = lc->env->GetFieldID(this->GetEntityClass(), "rotationPitch", "F");
	return lc->env->GetFloatField(playerInstance, pitch);
}

void CPlayer::setPitch(float pitch) {
	jfieldID pitchField = lc->env->GetFieldID(this->GetEntityClass(), "rotationPitch", "F");
	lc->env->SetFloatField(this->playerInstance, pitchField, pitch);
}

// --------------------

float CPlayer::GetHealth() {
	jmethodID getHealth = lc->env->GetMethodID(this->GetLivingBaseClass(), "getHealth", "()F");
	return lc->env->CallFloatMethod(this->playerInstance, getHealth);
}

jobject CPlayer::GetHeldItemStack() { // Returns an itemStack
	jmethodID getHeldItem = lc->env->GetMethodID(this->GetPlayerClass(), "getHeldItem", "()Lnet/minecraft/item/ItemStack;");
	return lc->env->CallObjectMethod(playerInstance, getHeldItem);
}

jobject CPlayer::GetHeldItem() {
	jclass itemStackClass = lc->GetClass("net.minecraft.item.ItemStack");
	jmethodID itemStackGetItemMethod = lc->env->GetMethodID(itemStackClass, "getItem", "()Lnet/minecraft/item/Item;");

	return lc->env->CallObjectMethod(this->GetHeldItemStack(), itemStackGetItemMethod);
}

std::string CPlayer::GetFacing() {
	// Target line : Minecraft.getMinecraft().thePlayer.getHorizontalFacing().getHorizontalIndex();
	jmethodID getHorizontalFacing = lc->env->GetMethodID(this->GetEntityClass(), "getHorizontalFacing", "()Lnet/minecraft/util/EnumFacing;");
	jobject facing = lc->env->CallObjectMethod(this->playerInstance, getHorizontalFacing);
	jclass EnumFacingClass = lc->GetClass("net.minecraft.util.EnumFacing");
	jmethodID getHorizontalIndex = lc->env->GetMethodID(EnumFacingClass, "getHorizontalIndex", "()I");
	int index = lc->env->CallIntMethod(facing, getHorizontalIndex);
	std::string facingStr = "";
	switch (index){
	case 0:
		facingStr = "SOUTH";
		break;
	case 1:
		facingStr = "WEST";
		break;
	case 2:
		facingStr = "NORTH";
		break;
	case 3:
		facingStr = "EAST";
		break;
	}
	return facingStr;
}