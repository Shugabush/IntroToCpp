#pragma once

class Zombie
{
	int Health;
	int Power;
	int Defense;

public:
	// Provides read-only access to health
	int GetHealth();

	// Attack another zombie
	// (will call TakeDamage to apply damage)
	void Attack(Zombie* victim);

	// Handle taking damage
	// (will consider DEF before subtracting health)
	void TakeDamage(int damageDealt);
};