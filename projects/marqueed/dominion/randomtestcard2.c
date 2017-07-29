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
	int handCount, deckCount, numPlayers, curPlayer, seed, cardRemaining, cardPlay, testNum, cardChoice1, cardChoice2, flag = 0;
	int k[10] = {adventurer, gardens, salvager, village, minion, mine, cutpurse, baron, steward, smithy};
	struct gameState testGame, prev_testGame;
	
	SelectStream(2);
	PutSeed(3);
	
	testNum = 2000;
	
	printf("\n*****START Testing random mine*****\n");
	
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
			
			// Random number of cards in deck from 0 to cardRemaining
			deckCount = floor(Random() * cardRemaining);
			testGame.deckCount[i] = deckCount;
			
			// Select random card to fill deck
			for(j = 0; j < deckCount; j++)
			{
				testGame.deck[i][j] = floor(Random() * (treasure_map + 1));
			}
		}
		
		//Ensure player has a mine card
		gainCard(mine, &testGame, 2, curPlayer);
		
		// Go through hand and select first treasure card, if no treasure card select last card in hand.
		for( i = 0; i < handCount; i++)
		{
			if(testGame.hand[curPlayer][i] == copper || testGame.hand[curPlayer][i] == silver || testGame.hand[curPlayer][i] == gold)
			{
				cardChoice1 = i;
				break;
			}
			else
			{
				cardChoice1 = i;
			}
		}
		
		// Random card for choice 2
		cardChoice2 = floor(Random() * (gold + 1));
		
//		printf("Choice 1: %d\n", testGame.hand[curPlayer][cardChoice1]);
//		printf("Choice 2: %d\n", cardChoice2);
		
		
		// Save game state
		memcpy(&prev_testGame, &testGame, sizeof(struct gameState));
		
		//Play mine
		cardPlay = playCard((testGame.handCount[curPlayer] - 1), cardChoice1, cardChoice2, 0, &testGame);
		if(cardPlay != 0)
		{
			printf("Error in cardPlay\n");
		}
		
		printf("\nTest %d\n", testCounter + 1);
//		printf("gainCard RT: %d\n", testGame.hand[curPlayer][testGame.handCount[curPlayer] - 1]);
	
		
		// Test for choice 1 out of range or choice 2 out of range 
		if((testGame.hand[curPlayer][cardChoice1] < copper || testGame.hand[curPlayer][cardChoice1] > gold) || (cardChoice2 > treasure_map || cardChoice2 < curse))
		{
			if(cardPlay != -1)
			{
				printf("TEST FAILED: Did not catch case choice 1 out of range or choice 2 out of range\n");
				flag = 1;
			}
			else
			{
				printf("OUT OF RANGE CHECK CIRCUMVENTED ALL OTHER TESTS!\n");
			}
		}
		else if((getCost(testGame.hand[curPlayer][cardChoice1]) - getCost(cardChoice2)) > 3)
		{
			if(cardPlay != -1)
			{
				printf("TEST FAILED: Did not catch case choice 2 no more than 3 coins more expensive choice 1\n");
				flag = 1;
			}
			else
			{
				printf("DELTA COST CHECK CIRCUMVENTED ALL OTHER TESTS!\n");
			}
		}
		else if(cardPlay == -1)
		{
			printf("TEST FAILED: Error checking in mine code failed\n");
			flag = 1;
		}
		else
		{
			// Test for hand count altered
			if(testGame.handCount[curPlayer] != prev_testGame.handCount[curPlayer] - 1)
			{
				printf("TEST FAILED: Hand count. Seen %d, Expected %d\n", testGame.handCount[curPlayer], prev_testGame.handCount[curPlayer] - 1);
				flag = 1;
			}
		
			// Test for deck count not altered
			if(testGame.deckCount[curPlayer] != prev_testGame.deckCount[curPlayer])
			{
				printf("TEST FAILED: Deck count. Seen %d, Expected %d\n", testGame.deckCount[curPlayer], prev_testGame.deckCount[curPlayer]);
				flag = 1;
			}
			
			// Test discard pile not altered change
			if(testGame.discardCount[curPlayer] != prev_testGame.discardCount[curPlayer])
			{
				printf("TEST FAILED: Discard count. Seen %d, Expected %d\n", testGame.discardCount[curPlayer], prev_testGame.discardCount[curPlayer]);
				flag = 1;
			}
			
			// Test played played pile altered change
			if(testGame.playedCardCount != prev_testGame.playedCardCount + 2)
			{
				printf("TEST FAILED: Play Card count. Seen %d, Expected %d\n", testGame.playedCardCount, prev_testGame.playedCardCount + 2);
				flag = 1;
			}
			
			if(cardPlay == -1)
			{
				testGame.hand[curPlayer][testGame.handCount[curPlayer] -1] == copper;
			}
						
			// Test for card added to be treasure card 
			if(testGame.hand[curPlayer][testGame.handCount[curPlayer] - 1] != copper && testGame.hand[curPlayer][testGame.handCount[curPlayer] - 1] != silver && testGame.hand[curPlayer][testGame.handCount[curPlayer] - 1] != gold)
			{
				printf("TEST FAILED: Card gained not a treasure card\n");
//				printf("Last Card in hand: %d\n", testGame.hand[curPlayer][testGame.handCount[curPlayer] - 1]);
				flag = 1;
			}
			
			// Test other players hand, deck, and  discard counts remain unchanged
			
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
			
			// Test Kingom/Victory piles altered
			kvNum = sizeof(testGame.supplyCount)/sizeof(int);
			for(i = 0; i < kvNum; i++)
			{
				if(testGame.supplyCount[i] != prev_testGame.supplyCount[i])
				{
					break;
				}
				else if (i == kvNum -1)
				{
					printf("TEST FAILED: Kingdom/Victory piles altered\n");
					flag = 1;	
				}
			}
			
		}
	}
	
	if(flag == 0)
	{
		printf("ALL TESTS SUCCESSFUL!\n");
	}
	
	
	printf("\n*****END Testing random mine*****\n");
	
	return 0;
}
