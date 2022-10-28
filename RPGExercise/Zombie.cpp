#include "Zombie.h"

#include <iostream>

Zombie::Zombie()
{
	Health = 0;
	Power = 0;
	Defense = 0;
}

Zombie::Zombie(Sword sword, Shield shield, int startHealth, int startPower, int startDefense)
{
	this->sword = sword;
	this->shield = shield;
	Health = startHealth;
	Power = startPower;
	Defense = startDefense;
}

int Zombie::GetHealth()
{
	return Health;
}
int Zombie::GetPower()
{
	return Power + sword.GetStrength();
}
int Zombie::GetDefense()
{
	return Defense + shield.GetStrength();
}

void Zombie::Attack(Zombie* victim)
{
	victim->TakeDamage(Power);
}

void Zombie::TakeDamage(int damageDealt)
{
	int actualDamage = damageDealt - Defense - shield.GetStrength();
	if (actualDamage < 1)
	{
		actualDamage = 1;
	}
	Health -= actualDamage;
}

bool Zombie::IsDead()
{
	return Health <= 0;
}
