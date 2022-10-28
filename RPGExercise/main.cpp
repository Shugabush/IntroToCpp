#include "Zombie.h"
#include "MathUtils.h"

#include <iostream>
#include <cassert>

int main()
{
	SeedRandom(nullptr);

	// min-inclusive
	// max-exclusive
	int randomInt = RandomRange(0, 11);

	// the number of zombies to have
	int zombieCount = RandomRange(5, 10);

	Zombie* zombies = new Zombie[zombieCount];
	Sword playerSword = { 2 };
	Shield playerShield = { 2 };
	zombies[0] = Zombie(playerSword, playerShield, 10, 2, 3); // for the player!
	zombies[0].Name = "Player";

	std::string names[] =
	{
		"John",
		"Uppy",
		"Mario",
		"Larissa",
		"Luigi",
		"Baird",
		"Sally",
		"Will",
		"Elizabeth",
		"Harold",
		"Alexa",
		"Todd Howard",
		"Alex"
	};
	int ancestry[13]{};

	// skip first zombie - that's for the player (special!)
	for (int i = 1; i < zombieCount; i++)
	{
		Sword sword = { 2 };
		Shield shield = { 2 };

		int startHealth = RandomRange(5, 11);
		zombies[i] = Zombie(sword, shield, startHealth, 2, 1);

		int nameIndex = RandomRange(0, 13);

		if (ancestry[nameIndex] == 0)
		{
			zombies[i].Name = names[nameIndex];
		}
		else
		{
			zombies[i].Name = names[nameIndex] + " the " + std::to_string(ancestry[nameIndex] + 1);
		}
		ancestry[nameIndex]++;
	}

	int zombiesLeft = zombieCount;

	while (zombiesLeft > 1)
	{
		for (int i = 0; i < zombiesLeft; i++)
		{
			// TODO: avoid attacking ourselves
				// pick a random target
			int targetIndex = (i + RandomRange(1, zombiesLeft)) % zombiesLeft;

			std::cout << "Zombie " << zombies[i].Name << " is attacking!" << std::endl;
			std::cout << "Zombie " << zombies[targetIndex].Name << " is targeted!" << std::endl;

			// attack as this zombie
			// the other zombie recieves damage
			zombies[i].Attack(&zombies[targetIndex]);

			// check for defeat
			if (zombies[targetIndex].IsDead())
			{
				std::cout << zombies[targetIndex].Name << " has been defeated!" << std::endl;

				// swap it with the last active zombie
				Zombie temp = zombies[zombiesLeft - 1];
				zombies[zombiesLeft - 1] = zombies[targetIndex];
				zombies[targetIndex] = temp;

				// decrement the zombiesLeft count
				zombiesLeft--;
			}

			std::cout << " ... " << std::endl;
		}
	}

	std::cout << zombies[0].Name << " is the victor!" << std::endl;

	// for clean-up!
	delete[] zombies;

	return 0;
}