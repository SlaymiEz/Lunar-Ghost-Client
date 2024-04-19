#include "EnumChatFormatting.h"

CEnumChatFormatting::CEnumChatFormatting() {
	std::cout << "Loaded the chat formatting" << std::endl;
}

void CEnumChatFormatting::c(std::string) {

}

jclass CEnumChatFormatting::GetClass() {
	return lc->GetClass("net.minecraft.util.EnumChatFormatting");
}

jobject CEnumChatFormatting::getValueByName(std::string friendlyName) {
	jmethodID getValueByName = lc->env->GetMethodID(this->GetClass(), "getValueByName", "(Ljava/lang/String;)Lnet/minecraft/util/EnumChatFormatting;");
	return lc->env->NewObject(this->GetClass(), getValueByName, friendlyName);
}