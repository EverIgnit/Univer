#include "Fixer.h"

Fixer::Fixer(int a) {
	val = a;
}

int Fixer::fix()
{
	if (val > 0)
		return val;
	else
		return val * -1;
}

