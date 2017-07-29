#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char** argv)
{
	int test;
	
	printf("\n*****START Testing getCost*****\n");

	
	printf("\nTest for Curse\n");
	test = getCost(curse);
	if(test == 0)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Estate\n");
	test = getCost(estate);
	if(test == 2)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Duchy\n");
	test = getCost(duchy);
	if(test == 5)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Province\n");
	test = getCost(province);
	if(test == 8)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Copper\n");
	test = getCost(copper);
	if(test == 0)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Silver\n");
	test = getCost(silver);
	if(test == 3)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Gold\n");
	test = getCost(gold);
	if(test == 6)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Adventurer\n");
	test = getCost(adventurer);
	if(test == 6)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Council Room\n");
	test = getCost(council_room);
	if(test == 5)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Feast\n");
	test = getCost(feast);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Gardens\n");
	test = getCost(gardens);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}

	printf("\nTest for Mine\n");
	test = getCost(mine);
	if(test == 5)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Remodel\n");
	test = getCost(remodel);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Smithy\n");
	test = getCost(smithy);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Village\n");
	test = getCost(village);
	if(test == 3)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Baron\n");
	test = getCost(baron);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Great Hall\n");
	test = getCost(great_hall);
	if(test == 3)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Minion\n");
	test = getCost(minion);
	if(test == 5)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Steward\n");
	test = getCost(steward);
	if(test == 3)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Tribute\n");
	test = getCost(tribute);
	if(test == 5)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Ambassador\n");
	test = getCost(ambassador);
	if(test == 3)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Cutpurse\n");
	test = getCost(cutpurse);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Embargo\n");
	test = getCost(embargo);
	if(test == 2)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Outpost\n");
	test = getCost(outpost);
	if(test == 5)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Salvager\n");
	test = getCost(salvager);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Sea Hag\n");
	test = getCost(sea_hag);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Treasure Map\n");
	test = getCost(treasure_map);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for Curse input as integer (0)\n");
	test = getCost(0);
	if(test == 0)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	
	printf("\nTest for Baron input as integer (15)\n");
	test = getCost(15);
	if(test == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for card not defined in program (30)\n");
	test = getCost(30);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\n*****END Testing getCost*****\n");
	
	return 0;
	
}