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

CPlayerSP CMinecraft::GetLocalPlayerSP() {
	jclass minecraftClass = this->GetClass();
	jobject minecraftObject = this->GetInstance();

	// Get playerSP
	jfieldID getPlayerSp = lc->env->GetFieldID(minecraftClass, "thePlayer", "Lnet/minecraft/client/entity/EntityPlayerSP;");
	jobject rtrnSp = lc->env->GetObjectField(minecraftObject, getPlayerSp);

	//lc->env->DeleteLocalRef(minecraftClass);
	lc->env->DeleteLocalRef(minecraftObject);

	return CPlayerSP(rtrnSp);
}