#pragma once

class Zombie
{
	int Health;
	int Power;
	int Defense;
public:
	Zombie();
	Zombie(int startHealth, int startPower, int startDefense);

	// Provides read-only access to health
	int GetHealth();

	// Attack another zombie
	// (will call TakeDamage to apply damage)
	void Attack(Zombie* victim);

	// Handle taking damage
	// (will consider DEF before subtracting health)
	void TakeDamage(int damageDealt);

	// Whether the zombie is dead or not
	bool IsDead();
};