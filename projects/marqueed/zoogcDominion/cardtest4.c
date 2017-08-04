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
	int test, i, cardTrash = 0, cardGain = 0;
	
	printf("\n*****START Testing mineRefact*****\n");

	testGame.handCount[0] = 5;
	testGame.hand[0][0] = copper;
	testGame.hand[0][1] = gold;
	testGame.hand[0][2] = mine;
	testGame.hand[0][3] = curse;
	testGame.hand[0][4] = ambassador;
	testGame.discardCount[0] = 0;
	testGame.deckCount[0] = 0;
	testGame.playedCardCount = 0;
	testGame.supplyCount[5] = 3;

	
	printf("\nTest for invalid card to trash (card < copper)\n");
	//test = mineRefact(0, &testGame, 2, 3, 6, 0, 0);
	test = cardEffect(mine, 3, 6, 0, &testGame, 2, 0);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for invalid card to trash (card > gold)\n");
	//test = mineRefact(0, &testGame, 2, 4, 6, 0, 0);
	test = cardEffect(mine, 4, 6, 0, &testGame, 2, 0);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for invalid card to gain (card < curse)\n");
	//test = mineRefact(0, &testGame, 2, 0, -1, 0, 0);
	test = cardEffect(mine, 0, -1, 0, &testGame, 2, 0);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for invalid card to gain (card > treasure_map)\n");
	//test = mineRefact(0, &testGame, 2, 0, 27, 0, 0);
	test = cardEffect(mine, 0, 27, 0, &testGame, 2, 0);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for invalid card to gain (cost difference > 3)\n");
	//test = mineRefact(0, &testGame, 2, 0, 6, 0, 0);
	test = cardEffect(mine, 0, 6, 0, &testGame, 2, 0);
	if(test == -1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
		testGame.handCount[0] = 5;
		testGame.hand[0][0] = copper;
		testGame.hand[0][1] = gold;
		testGame.hand[0][2] = mine;
		testGame.hand[0][3] = curse;
		testGame.hand[0][4] = ambassador;
		testGame.discardCount[0] = 0;
		testGame.deckCount[0] = 0;
		testGame.playedCardCount = 0;
		testGame.supplyCount[5] = 3;
	}
	
	printf("\nTest for silver gain to hand\n");
	//test = mineRefact(0, &testGame, 2, 0, 5, 0, 0);
	test = cardEffect(mine, 0, 5, 0, &testGame, 2, 0);
	printf("Player should have gained silver(5)\n");
	for(i = 0; i < testGame.handCount[0]; i++)
	{
		if(testGame.hand[0][i] == silver)
		{
			cardGain = 1;
		}
	}
	if(cardGain == 1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	
	printf("\nTest for correct number of discarded cards\n");
	printf("Player hand count is: %d\n", testGame.handCount[0]);
	if(testGame.handCount[0] == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for mine discard\n");
	printf("Player played card should be mine(11): %d\n", testGame.playedCards[0]);
	if(testGame.playedCards[0] == 11)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	
	printf("\nTest for copper trash\n");
	for(i = 0; i < testGame.handCount[0]; i++)
	{
		if(testGame.hand[0][i] != copper)
		{
			cardTrash = 1;
		}
	}
	
	if(cardTrash == 1)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\n*****END Testing mineRefact*****\n");
	
	return 0;
	
}