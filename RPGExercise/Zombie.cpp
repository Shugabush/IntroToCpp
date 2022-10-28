#include "Zombie.h"

#include <iostream>

Zombie::Zombie()
{
	Health = 0;
	Power = 0;
	Defense = 0;
}

Zombie::Zombie(int startHealth, int startPower, int startDefense)
{
	Health = startHealth;
	Power = startPower;
	Defense = startDefense;
}

int Zombie::GetHealth()
{
	return Health;
}

void Zombie::Attack(Zombie* victim)
{
	victim->TakeDamage(Power);
}

void Zombie::TakeDamage(int damageDealt)
{
	int actualDamage = damageDealt - Defense;
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
