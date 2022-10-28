#include "Zombie.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(nullptr));

	// min-inclusive
	// max-exclusive
	int randomInt = std::rand() % 10;

	// the number of zombies to have
	int zombieCount = 5 + (std::rand() % 3);

	Zombie* zombies = new Zombie[zombieCount];
	zombies[0] = Zombie(10, 6, 3); // for the player!

	// skip first zombie - that's for the player (special!)
	for (int i = 1; i < zombieCount; i++)
	{
		int startHealth = 10 + (std::rand() % 6);
		zombies[i] = Zombie(startHealth, 2, 1);
	}

	int zombiesLeft = zombieCount;

	int loopCount = 0;

	while (zombiesLeft > 1)
	{
		loopCount++;
		zombiesLeft = zombieCount;
		for (int i = 0; i < zombieCount; i++)
		{
			if (!zombies[i].IsDead())
			{
				int targetZombieIndex = std::rand() % zombieCount;
				if (targetZombieIndex >= i && targetZombieIndex < zombieCount - 1)
				{
					targetZombieIndex++;
				}
				zombies[i].Attack(&zombies[targetZombieIndex]);
			}
			else
			{
				Zombie temp = zombies[i];
				zombies[i] = zombies[zombieCount - 1];
				zombies[zombieCount - 1] = temp;
				zombiesLeft--;
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