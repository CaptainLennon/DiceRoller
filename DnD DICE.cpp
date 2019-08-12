// DnD DICE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdio.h>

bool bNAT20 = false;
bool bNAT1 = false;

int RollDice(int adv = 0, int dMod = 0, int dNumber = 1, int dSides = 20)
{
	bNAT20 = false;
	bNAT1 = false;
	int dRoll, advRoll;
	int dResult = 0;

	if (adv > 0)							// advantage or disadvantage selected
	{
		dRoll = rand() % 20 + 1;			// first d20 roll
		advRoll = rand() % 20 + 1;			// second d20 roll
		if (adv == 1)						// advantage selected, keep highest
		{
			if (dRoll > advRoll)
			{
				dResult = dRoll;
			}
			else
			{ 
				dResult = advRoll;
			}
		}
		else if (adv >= 2)					// disadvantage selected, keep lowest
		{
			if (dRoll < advRoll)
			{
				dResult = dRoll;
			}
			else
			{
				dResult = advRoll;
			}
		}
	}
	else									// regular dice rolling, add together
	{
		for (int i = 1; i <= dNumber; i++)
		{
			dRoll = rand() % dSides + 1;
			dResult += dRoll;
		}
	}

	if (dSides == 20 && dResult == 20)		// check for Natural 20 on d20
	{
		bNAT20 = true;
	}
	else if (dSides == 20 && dResult == 1)	// check for Natural 1 on d20
	{
		bNAT1 = true;
	}

	dResult += dMod;						// add the roll modifier to the dice result
	return dResult;
}


void CritMiss()
{
	if (bNAT20 == true)
	{
		printf("Critical Hit!\n");
	}
	else if (bNAT1 == true)
	{
		printf("Critical Miss!\n");
	}
	else
	{
		printf("\n");
	}
}


int main()
{
	srand(time(NULL)); // required for random number generation

	// Dice(0-none/1-adv/2-dis, modifier to be added, number of dice, number of sides on dice)
	// 1-advantage rolls 2d20 and keeps the greater result
	// 2-disadvantage rolls 2d20 and keeps the lower result

	printf("25 Dice Rolls:\n\n");

	for (int i = 0; i < 25; i++)
	{
		printf("%d ", RollDice(0));
		CritMiss();
	}

	return 0;
}