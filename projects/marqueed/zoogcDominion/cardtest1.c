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
	int test, i;
	
	printf("\n*****START Testing smithyRefact*****\n");

	testGame.handCount[0] = 1;
	testGame.hand[0][0] = smithy;
	testGame.discardCount[0] = 0;
	testGame.deckCount[0] = 0;
	testGame.playedCardCount = 0;
	
	for(i = 0; i < 10; i++)
	{
		testGame.deck[0][i] = copper;
		testGame.deckCount[0]++;
	}
	
	printf("\nTest for smithy return 0\n");
	//test = smithyFunction(&testGame, 0);
	test = cardEffect(smithy, 0, 0, 0, &testGame, 0, 0);
	if(test == 0)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for smithy discard\n");
	printf("Player played card should be smithy(13): %d\n", testGame.playedCards[0]);
	if(testGame.playedCards[0] == 13)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	
	printf("\nTest for smithy player handCount\n");
	printf("Player hand count is: %d\n", testGame.handCount[0]);
	if(testGame.handCount[0] == 3)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\n*****END Testing smithyRefact*****\n");
	
	return 0;
	
}