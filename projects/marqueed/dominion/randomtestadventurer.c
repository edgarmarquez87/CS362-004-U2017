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
	int i, j, testCounter, kvNum;
	int handCount, deckCount, numPlayers, curPlayer, seed, cardRemaining, cardPlay, testNum, flag = 0;
	int k[10] = {adventurer, gardens, salvager, village, minion, mine, cutpurse, baron, steward, smithy};
	struct gameState testGame, prev_testGame;
	
	SelectStream(2);
	PutSeed(3);
	
	testNum = 2000;
	
	printf("\n*****START Testing random adventurer*****\n");
	
	for(testCounter = 0; testCounter < testNum; testCounter++)
	{
		// Random number of players ranging from 2 to MAX_PLAYERS
		numPlayers = floor(Random() * (MAX_PLAYERS - 2)) + 2;
		seed = floor(Random() * 2000);
		initializeGame(numPlayers, k, seed, &testGame);
		
		// Pick a random player to be current player
		curPlayer = floor(Random() * numPlayers);
		testGame.whoseTurn = curPlayer;
		
		// Random number of cards in players hands
		for (i = 0; i < numPlayers; i++)
		{
			// Random number of card in hand from 0 to MAX_HAND
			handCount = floor(Random() * MAX_HAND);
			testGame.handCount[i] = handCount;
			
			// Select random card to fill hand
			for( j = 0; j < handCount; j++)
			{
				testGame.hand[i][j] = floor(Random() * (treasure_map + 1));
			}
		}
		
		// Random number of cards in players deck
		for (i = 0; i < numPlayers; i++)
		{
			// Set number of possible cards remaining for deck
			cardRemaining = MAX_DECK - testGame.handCount[i];
			
			// Random number of cards in deck from 10 to cardRemaining
			deckCount = floor(Random() * cardRemaining);
			testGame.deckCount[i] = deckCount;			
			
			// Select random card to fill deck
			for(j = 0; j < deckCount; j++)
			{
				testGame.deck[i][j] = floor(Random() * (treasure_map + 1));
			}
		}
		
		//Ensure player has an adventurer card
		gainCard(adventurer, &testGame, 2, curPlayer);
		
		// Save game state
		memcpy(&prev_testGame, &testGame, sizeof(struct gameState));
				
		//Play adventurer
		cardPlay = playCard((testGame.handCount[curPlayer] - 1), 0, 0, 0, &testGame);
		if(cardPlay != 0)
		{
			printf("Error in cardPlay\n");
		}
				
		printf("\nTest %d\n", testCounter + 1);
		
		// Test for increased hand count (2 added 1 discarded)
		if(testGame.handCount[curPlayer] != prev_testGame.handCount[curPlayer] + 1)
		{
			printf("TEST FAILED: Hand count. Seen %d, Expected %d\n", testGame.handCount[curPlayer], prev_testGame.handCount[curPlayer] + 1);
			flag = 1;
		}
		
		// Test for #1 card added to be treasure card 
		if(testGame.hand[curPlayer][testGame.handCount[curPlayer] - 2] != copper && testGame.hand[curPlayer][testGame.handCount[curPlayer] - 2] != silver && testGame.hand[curPlayer][testGame.handCount[curPlayer] - 2] != gold)
		{
			printf("TEST FAILED: Card gained not a treasure card\n");
			flag = 1;
		}
		
		// Test for #2 card added to be treasure card 
		if(testGame.hand[curPlayer][testGame.handCount[curPlayer] - 1] != copper && testGame.hand[curPlayer][testGame.handCount[curPlayer] - 1] != silver && testGame.hand[curPlayer][testGame.handCount[curPlayer] - 1] != gold)
		{
			printf("TEST FAILED: Card gained not a treasure card\n");
			flag = 1;
		}
	
		
		// Test for decreased deck count at least fewer than 2
		if(testGame.deckCount[curPlayer] > prev_testGame.deckCount[curPlayer] - 2)
		{
			printf("TEST FAILED: Deck count. Seen %d, Expected %d\n", testGame.deckCount[curPlayer], prev_testGame.deckCount[curPlayer] - 2);
			flag = 1;
		}
		
				
		// Test other players hand, deck, and  disard counts remain unchanged
		
		for(i = 0; i < numPlayers; i++)
		{
			if(i != curPlayer)
			{
				// Test hand count
				if(testGame.handCount[i] != prev_testGame.handCount[i])
				{
					printf("TEST FAILED: Player %d has altered hand count\n", i);
					flag = 1;
				}
				
				// Test deck count
				if(testGame.deckCount[i] != prev_testGame.deckCount[i])
				{
					printf("TEST FAILED: Player %d has altered deck count\n", i);
					flag = 1;
				}
				
				// Test discard pile count
				if(testGame.discardCount[i] != prev_testGame.discardCount[i])
				{
					printf("TEST FAILED: Player %d has altered discard pile count\n", i);
					flag = 1;
				}
				
			}
		}
		
		// Test Kingom/Victory piles unchanged
		kvNum = sizeof(testGame.supplyCount)/sizeof(int);
		for(i = 0; i < kvNum; i++)
		{
			if(testGame.supplyCount[i] != prev_testGame.supplyCount[i])
			{
				printf("TEST FAILED: Kingdom/Victory piles altered\n");
				flag = 1;
			}
		}
		
	}
	
	if(flag == 0)
	{
		printf("ALL TESTS SUCCESSFUL!\n");
	}
	
	printf("\n*****END Testing random adventurer*****\n");
	
	return 0;
}
