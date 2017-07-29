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
	int test, i, z = 0, cardDrawn, temphand[500];
	int countAdv = 0, countCopp = 0, countTreas = 0;
	int drawntreasure = 0;
	
	printf("\n*****START Testing adventurerRefact*****\n");
	
	testGame.handCount[0] = 5;
	testGame.discardCount[0] = 6;
	testGame.deckCount[0] = 5;
	testGame.playedCardCount = 0;
	
	testGame.discard[0][0] = copper;	
	testGame.discard[0][1] = copper;
	testGame.discard[0][2] = silver;
	testGame.discard[0][3] = silver;
	testGame.discard[0][4] = gold;
	testGame.discard[0][5] = gold;
			
	printf("\nTest for copper to end loop and return 0\n");
	
	testGame.hand[0][0] = adventurer;
	testGame.hand[0][1] = adventurer;
	testGame.hand[0][2] = adventurer;
	testGame.hand[0][3] = adventurer;
	testGame.hand[0][4] = adventurer;
	
	testGame.deck[0][0] = smithy;
	testGame.deck[0][1] = copper;
	testGame.deck[0][2] = cutpurse;
	testGame.deck[0][3] = copper;
	testGame.deck[0][4] = minion;

	test = adventurerRefact(0, &testGame, temphand, drawntreasure, cardDrawn, z);
	for(i = 0; i < testGame.handCount[0]; i++)
	{
		if(testGame.hand[0][i] == copper)
		{
			countTreas++;
		}
	}
	
	if(test == 0 && countTreas == 2)
	{
		printf("Test Passed! :)\n");
		countTreas = 0;
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for proper number of cards discarded\n");
	if(testGame.discardCount[0] == 9)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	
	printf("\nTest for proper cards in hand (4 adventurers & 2 copper)\n");
	for(i = 0; i < testGame.handCount[0]; i++)
	{
		if(testGame.hand[0][i] == adventurer)
		{
			countAdv++;
		}
		if(testGame.hand[0][i] == copper)
		{
			countCopp++;
		}
	}
	
	printf("countAdv: %d\n", countAdv);
	printf("countCopp: %d\n", countCopp);
	
	if(countAdv == 4 && countCopp ==2)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	
			
	printf("\nTest for silver to end loop and return 0\n");
	testGame.handCount[1] = 5;
	testGame.discardCount[1] = 6;
	testGame.deckCount[1] = 5;
	testGame.playedCardCount = 0;
	
	testGame.discard[1][0] = copper;	
	testGame.discard[1][1] = copper;
	testGame.discard[1][2] = silver;
	testGame.discard[1][3] = silver;
	testGame.discard[1][4] = gold;
	testGame.discard[1][5] = gold;
	
	testGame.hand[1][0] = adventurer;
	testGame.hand[1][1] = adventurer;
	testGame.hand[1][2] = adventurer;
	testGame.hand[1][3] = adventurer;
	testGame.hand[1][4] = adventurer;
	
	testGame.deck[1][0] = smithy;
	testGame.deck[1][1] = silver;
	testGame.deck[1][2] = cutpurse;
	testGame.deck[1][3] = silver;
	testGame.deck[1][4] = minion;

	test = adventurerRefact(1, &testGame, temphand, drawntreasure, cardDrawn, z);
	for(i = 0; i < testGame.handCount[1]; i++)
	{
		if(testGame.hand[1][i] == silver)
		{
			countTreas++;
		}
	}
	
	if(test == 0 && countTreas == 2)
	{
		printf("Test Passed! :)\n");
		countTreas = 0;
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	
	printf("\nTest for gold to end loop and return 0\n");
	testGame.handCount[2] = 5;
	testGame.discardCount[2] = 6;
	testGame.deckCount[2] = 5;
	testGame.playedCardCount = 0;
	
	testGame.discard[2][0] = copper;	
	testGame.discard[2][1] = copper;
	testGame.discard[2][2] = silver;
	testGame.discard[2][3] = silver;
	testGame.discard[2][4] = gold;
	testGame.discard[2][5] = gold;
	
	testGame.hand[2][0] = adventurer;
	testGame.hand[2][1] = adventurer;
	testGame.hand[2][2] = adventurer;
	testGame.hand[2][3] = adventurer;
	testGame.hand[2][4] = adventurer;
	
	testGame.deck[2][0] = smithy;
	testGame.deck[2][1] = gold;
	testGame.deck[2][2] = cutpurse;
	testGame.deck[2][3] = gold;
	testGame.deck[2][4] = minion;

	test = adventurerRefact(2, &testGame, temphand, drawntreasure, cardDrawn, z);
	for(i = 0; i < testGame.handCount[2]; i++)
	{
		if(testGame.hand[2][i] == gold)
		{
			countTreas++;
		}
	}
	
	if(test == 0 && countTreas == 2)
	{
		printf("Test Passed! :)\n");
		countTreas = 0;
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for shuffle to end loop and return 0\n");
	testGame.handCount[3] = 5;
	testGame.discardCount[3] = 6;
	testGame.deckCount[3] = 0;
	testGame.playedCardCount = 0;
	
	testGame.discard[3][0] = copper;	
	testGame.discard[3][1] = copper;
	testGame.discard[3][2] = silver;
	testGame.discard[3][3] = silver;
	testGame.discard[3][4] = gold;
	testGame.discard[3][5] = gold;
	
	testGame.hand[3][0] = adventurer;
	testGame.hand[3][1] = adventurer;
	testGame.hand[3][2] = adventurer;
	testGame.hand[3][3] = adventurer;
	testGame.hand[3][4] = adventurer;
	

	test = adventurerRefact(3, &testGame, temphand, drawntreasure, cardDrawn, z);
	for(i = 0; i < testGame.handCount[3]; i++)
	{
		if(testGame.hand[3][i] == copper || testGame.hand[3][i] == silver || testGame.hand[3][i] == gold)
		{
			countTreas++;
		}
	}
	
	if(test == 0 && countTreas == 2)
	{
		printf("Test Passed! :)\n");
		countTreas = 0;
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\n*****END Testing adventurerRefact*****\n");
	
	return 0;
	
}