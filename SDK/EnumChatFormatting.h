#pragma once
#include "../Java.h"

class CEnumChatFormatting {
public:
	CEnumChatFormatting();
	
	void c(std::string s);
	jobject getValueByName(std::string friendlyName);
private:
	jclass GetClass();
};