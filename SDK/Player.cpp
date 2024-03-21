#include "Player.h"
#include <stdio.h>
#include <excpt.h>

CPlayer::CPlayer(jobject instance) {
	this->playerInstance = instance;
}

void CPlayer::Cleanup() {
	lc->env->DeleteLocalRef(this->playerInstance);
}

jclass CPlayer::GetClass() {
	return lc->GetClass("net.minecraft.entity.player.EntityPlayer");
}

void CPlayer::clear() {
	jclass playerClass = this->GetClass();
	jfieldID playerInventoryField = lc->env->GetFieldID(playerClass, "inventory", "Lnet/minecraft/entity/player/EntityPlayer;");
	jobject playerInventoryObj = lc->env->GetObjectField(playerInstance, playerInventoryField);

	jclass inventoryClass = lc->GetClass("net.minecraft.entity.player.InventoryPlayer;");
	jmethodID getclearMethod= lc->env->GetMethodID(inventoryClass, "clear", "()V");
	if (playerInventoryObj && getclearMethod) {
		try {
			lc->env->CallVoidMethod(playerInventoryObj, getclearMethod);
		}
		catch (const std::exception e) {
			printf("Exception occured!\n", e.what());
		}
	}
	else {
		fprintf(stderr, "Missing objects");
	}
}