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
	int i, j;
	
	printf("\n*****START Testing cutpurseRefact*****\n");

	testGame.numPlayers = 3;
	
	for(i = 0; i < testGame.numPlayers; i++)
	{
		testGame.handCount[i] = 5;
		testGame.discardCount[i] = 0;
		testGame.deckCount[i] = 0;
	}
	
	for(i = 0; i < testGame.numPlayers; i++)
	{
		for(j = 0; j < testGame.handCount[i]; j++)
		{
			if(i == 0)
			{
				testGame.hand[i][j] = cutpurse;
			}
			else if(i == 1)
			{
				testGame.hand[i][j] = copper;
			}
			else 
			{
				testGame.hand[i][j] = silver;
			}
		}
	}
	
	testGame.coins = 0;
	testGame.playedCardCount = 0;
	
	cardEffect(cutpurse, 0, 0, 0, &testGame, 0, 0);
			
	printf("\nTest for coin update to 2\n");
	if(testGame.coins == 2)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for player[1] lose copper\n");
	printf("Player[1] should only have 4 cards in hand: %d\n", testGame.handCount[1]);
	if(testGame.handCount[1] == 4)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for player[2] no card loss\n");
	printf("Player[2] should have kept all 5 cards in hand: %d\n", testGame.handCount[2]);
	if(testGame.handCount[2] == 5)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for player[0] discard\n");
	printf("Player[0] should have 4 cards in hand: %d\n", testGame.handCount[0]);
	printf("Played cards should be 2 (1 copper & 1 cutpurse): %d\n", testGame.playedCardCount);
	if(testGame.handCount[0] == 4 && testGame.playedCardCount == 2)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\n*****END Testing cutpurseRefact*****\n");
	
	return 0;
	
}