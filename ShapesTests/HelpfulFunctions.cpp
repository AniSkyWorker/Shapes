#include "stdafx.h"
#include "HelpfulFunctions.h"

bool AreColorsEqual(const Color & first, const Color & second)
{
	return first.r == second.r && first.b == second.b && first.g == second.g;
}
