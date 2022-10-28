#pragma once

#include "Inventory.h"

#include <string>

class Zombie
{

public:
	std::string Name;
	bool IsPlayer;

	int MaxHealth;
	int Health;
	int Power;
	int Defense;
	Shield shield;
	Sword sword;

	Zombie();
	Zombie(Sword sword, Shield shield, int startHealth, int startPower, int startDefense);

	// Provides read-only access to health, power, and defense
	int GetHealth();
	int GetPower();
	int GetDefense();

	// Attack another zombie
	// (will call TakeDamage to apply damage)
	void Attack(Zombie* victim);

	void Heal(int healing);

	// Handle taking damage
	// (will consider DEF before subtracting health)
	void TakeDamage(int damageDealt);

	// Whether the zombie is dead or not
	bool IsDead();
};