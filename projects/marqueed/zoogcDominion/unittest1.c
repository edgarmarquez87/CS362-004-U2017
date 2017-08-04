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
	struct gameState testGame;
	int test;
	
	printf("\n*****START Testing buyCard*****\n");
	
	testGame.numBuys = 0;
	testGame.supplyCount[gold] = 2;
	testGame.coins = 0;
	
	printf("\nTest for player with no buys\n");
	
	test = buyCard(6, &testGame);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for player with too few coins\n");
	testGame.numBuys = 1;
	
	test = buyCard(6, &testGame);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for player with more coins than card cost\n");
	testGame.numBuys = 3;
	testGame.coins = 12;
	
	test = buyCard(6, &testGame);
	if(test == 0)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	
	printf("\nTest for player with exact coins for card cost\n");
	
	test = buyCard(6, &testGame);
	if(test == 0)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for drained card supply\n");
	
	test = buyCard(6, &testGame);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\n*****END Testing buyCard*****\n");
	
	return 0;
	
}