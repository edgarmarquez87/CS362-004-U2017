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
	
	printf("\n*****START Testing updateCoins*****\n");
	testGame.coins = 100; //Will test if coins is reset upon entering updateCoins()
	int bonus = 318;
	testGame.handCount[0] = 10;
	
	printf("\nTest for player with no Treasure cards in hand\n");
	for(i = 0; i < 10; i++)
	{
		testGame.hand[0][i] = smithy;
	}
	
	updateCoins(0, &testGame, 0);
	test = testGame.coins;
	printf("Player should have 0 coins: %d.\n", test);
	if(test == 0)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for player with no Treasure cards in hand but with bonus\n");
	updateCoins(0, &testGame, bonus);
	test = testGame.coins;
	printf("Player should have 318 coins: %d.\n", test);
	if(test == 318)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for player with all copper Treasure cards in hand\n");
	for(i = 0; i < 10; i++)
	{
		testGame.hand[0][i] = copper;
	}
	
	updateCoins(0, &testGame, 0);
	test = testGame.coins;
	printf("Player should have 10 coins: %d.\n", test);
	if(test == 10)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for player with all silver Treasure cards in hand\n");
	for(i = 0; i < 10; i++)
	{
		testGame.hand[0][i] = silver;
	}
	updateCoins(0, &testGame, 0);
	test = testGame.coins;
	printf("Player should have 20 coins: %d.\n", test);
	if(test == 20)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for player with all gold Treasure cards in hand\n");
	for(i = 0; i < 10; i++)
	{
		testGame.hand[0][i] = gold;
	}
	updateCoins(0, &testGame, 0);
	test = testGame.coins;
	printf("Player should have 30 coins: %d.\n", test);
	if(test == 30)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}
	
	printf("\nTest for all types of cards in hand\n");
	testGame.handCount[0] = 27;
	
	testGame.hand[0][0] = curse;
	testGame.hand[0][1] = estate;
	testGame.hand[0][2] = duchy;
	testGame.hand[0][3] = province;
	testGame.hand[0][4] = copper;
	testGame.hand[0][5] = adventurer;
	testGame.hand[0][6] = council_room;
	testGame.hand[0][7] = feast;
	testGame.hand[0][8] = gardens;
	testGame.hand[0][9] = mine;
	testGame.hand[0][10] = remodel;
	testGame.hand[0][11] = smithy;
	testGame.hand[0][12] = village;
	testGame.hand[0][13] = silver;
	testGame.hand[0][14] = baron;
	testGame.hand[0][15] = great_hall;
	testGame.hand[0][16] = minion;
	testGame.hand[0][17] = steward;
	testGame.hand[0][18] = tribute;
	testGame.hand[0][19] = ambassador;
	testGame.hand[0][20] = cutpurse;
	testGame.hand[0][21] = embargo;
	testGame.hand[0][22] = outpost;
	testGame.hand[0][23] = salvager;
	testGame.hand[0][24] = sea_hag;
	testGame.hand[0][25] = treasure_map;
	testGame.hand[0][26] = gold;

	updateCoins(0, &testGame, 0);
	test = testGame.coins;
	printf("Player should have 6 coins: %d.\n", test);
	if(test == 6)
	{
		printf("Test Passed! :)\n");
	}
	else
	{
		printf("Test Failed! :(\n");
	}

	
	printf("\n*****END Testing updateCoins*****\n");
	
	return 0;
	
}