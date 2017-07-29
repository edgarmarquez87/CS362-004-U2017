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
	
	printf("\n*****START Testing gainCard*****\n");

	testGame.handCount[0] = 0;
	testGame.supplyCount[gold] = -1;
	
	printf("\nTest for card not used in game\n");
	test = gainCard(6, &testGame, 0, 0);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	
	printf("\nTest for card not used in game\n");
	testGame.supplyCount[gold] = 0;
	test = gainCard(6, &testGame, 0, 0);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}

	
	printf("\nTest for card added to deck\n");
	testGame.supplyCount[gold] = 3;
	gainCard(6, &testGame, 1, 0);
	if(testGame.deckCount[0] == 1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for card added to hand\n");
	gainCard(6, &testGame, 2, 0);
	if(testGame.handCount[0] == 1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for card added to discard\n");
	gainCard(6, &testGame, 0, 0);
	if(testGame.discardCount[0] == 1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest card added to hand is what was requested\n");
	test = handCard(0, &testGame);
	if(test == 6)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest decrease in supplyCount\n");
	if(testGame.supplyCount[6] == 0)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\n*****END Testing gainCard*****\n");
	
	return 0;
	
}