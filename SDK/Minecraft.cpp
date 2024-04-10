#include "Minecraft.h"

jclass CMinecraft::GetClass() {
	return lc->GetClass("net.minecraft.client.Minecraft");
}



jobject CMinecraft::GetInstance() {
	jclass minecraftClass = this->GetClass();

	jfieldID getMinecraft = lc->env->GetStaticFieldID(minecraftClass, "theMinecraft", "Lnet/minecraft/client/Minecraft;");
	jobject rtrn = lc->env->GetStaticObjectField(minecraftClass, getMinecraft);

	return rtrn;
}

CPlayer CMinecraft::GetLocalPlayer() {
	jclass minecraftClass = this->GetClass();
	jobject minecraftObject = this->GetInstance();

	// Get playerSP
	jfieldID getPlayerSp = lc->env->GetFieldID(minecraftClass, "thePlayer", "Lnet/minecraft/client/entity/EntityPlayerSP;");
	jobject rtrnSp = lc->env->GetObjectField(minecraftObject, getPlayerSp);

	//lc->env->DeleteLocalRef(minecraftClass);
	lc->env->DeleteLocalRef(minecraftObject);

	return CPlayer(rtrnSp);
}

CWorld CMinecraft::GetLocalWorld() {
	jclass minecraftClass = this->GetClass();
	jobject minecraftObject = this->GetInstance();

	jfieldID getWorld = lc->env->GetFieldID(minecraftClass, "theWorld", "Lnet/minecraft/client/multiplayer/WorldClient;");
	jobject rtrn = lc->env->GetObjectField(minecraftObject, getWorld);

	lc->env->DeleteLocalRef(minecraftObject);

	return CWorld(rtrn);
}

CPlayerController CMinecraft::GetLocalPlayerController() {
	jclass minecraftClass = this->GetClass();
	jobject minecraftObject = this->GetInstance();

	jfieldID getPlayerController = lc->env->GetFieldID(minecraftClass, "playerController", "Lnet/minecraft/client/multiplayer/PlayerControllerMP;");
	jobject rtrn = lc->env->GetObjectField(minecraftObject, getPlayerController);

	lc->env->DeleteLocalRef(minecraftObject);

	return CPlayerController(rtrn);
}