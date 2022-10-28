#include "Inventory.h"

Shield::Shield()
{
	ExtraDefense = 0;
}
Shield::Shield(int defense)
{
	ExtraDefense = defense;
}
int Shield::GetStrength()
{
	return ExtraDefense;
}

Sword::Sword()
{
	ExtraPower = 0;
}
Sword::Sword(int power)
{
	ExtraPower = power;
}
int Sword::GetStrength()
{
	return ExtraPower;
}
