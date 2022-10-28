#pragma once

class Sword
{
	int ExtraPower;

public:
	Sword();
	Sword(int power);

	int GetStrength();
};

class Shield
{
	int ExtraDefense;

public:
	Shield();
	Shield(int defense);

	int GetStrength();
};