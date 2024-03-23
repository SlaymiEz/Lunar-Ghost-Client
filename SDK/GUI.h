#pragma once

#include "../Java.h"

class CGUI {
public:
	jclass GetClass();
	jclass GetScaledResolutionClass();

	int getScaledWidth();
	int getScaledHeight();
};

