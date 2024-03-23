#include "GUI.h"

jclass CGUI::GetClass() {
	return lc->GetClass("net.minecraft.client.gui.GuiScreen");
}

jclass CGUI::GetScaledResolutionClass() {
	return lc->GetClass("net.minecraft.client.gui.ScaledResolution");
}

int CGUI::getScaledHeight() {
	jclass scaledResolutionClass = this->GetScaledResolutionClass();
	jfieldID scaledHeight = lc->env->GetFieldID(scaledResolutionClass, "getScaledHeight", "()I");

	
	
}

int CGUI::getScaledWidth() {

}