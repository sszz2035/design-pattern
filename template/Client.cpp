#include "Combo/ComboA.h"
#include "Combo/ComboB.h"
#include"memory"
int main()
{
	auto comboPtrA = std::make_unique<temp::ComboA>();
	auto comboPtrB = std::make_unique<temp::ComboB>();
	comboPtrA->performTrip();
	comboPtrB->performTrip();
	return 0;
}