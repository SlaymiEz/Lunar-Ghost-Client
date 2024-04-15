#include "EnumFacing.h"

jclass CEnumFacing::GetClass() {
	return lc->GetClass("net.minecraft.util.EnumFacing");
}

CEnumFacing::CEnumFacing() {
	std::cout << "Loaded the EnumFacing" << std::endl;
}
