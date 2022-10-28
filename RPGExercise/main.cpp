#include "Zombie.h"
#include "MathUtils.h"

#include <iostream>

int main()
{
	SeedRandom(nullptr);

	// min-inclusive
	// max-exclusive
	int randomInt = RandomRange(0, 11);

	// the number of zombies to have
	int zombieCount = RandomRange(5, 7);

	Zombie* zombies = new Zombie[zombieCount];
	Sword playerSword = { 5 };
	Shield playerShield = { 5 };
	zombies[0] = Zombie(playerSword, playerShield, 20, 6, 3); // for the player!

	// skip first zombie - that's for the player (special!)
	for (int i = 1; i < zombieCount; i++)
	{
		Sword sword = { 2 };
		Shield shield = { 2 };

		int startHealth = RandomRange(5, 11);
		zombies[i] = Zombie(sword, shield, startHealth, 2, 1);
	}

	int zombiesLeft = zombieCount;

	while (zombiesLeft > 1)
	{
		for (int i = 0; i < zombiesLeft; i++)
		{
			if (!zombies[i].IsDead())
			{
				int targetZombieIndex = RandomRange(0, zombieCount);
				if (targetZombieIndex >= i && targetZombieIndex < zombieCount - 1)
				{
					targetZombieIndex++;
				}

				if (zombies[targetZombieIndex].IsDead())
				{
					std::cout << "WARNING: ATTACKING A DEAD ZOMBIE" << std::endl;
				}
				
				zombies[i].Attack(&zombies[targetZombieIndex]);
				
				std::cout << "Zombie " << i;
				std::cout << " attacked zombie " << targetZombieIndex;
				std::cout << ", dealing " << zombies[i].GetPower() << " damage" << std::endl;
				
				std::cout << "Zombie " << targetZombieIndex << " has " << zombies[targetZombieIndex].GetHealth() << " left\n" << std::endl;
			}
			else
			{
				zombiesLeft--;
				Zombie temp = zombies[i];
				zombies[i] = zombies[zombiesLeft - 1];
				if (zombies[zombiesLeft - 1].IsDead())
				{
					std::cout << "here" << std::endl;
				}
				zombies[zombiesLeft - 1] = temp;
				
			}
		}
	}
	if (zombies[0].IsDead())
	{
		// We lost!
		std::cout << "Defeat!" << std::endl;
	}
	else
	{
		// We won!
		std::cout << "Victory!" << std::endl;
	}

	// for clean-up!
	delete[] zombies;

	return 0;
}