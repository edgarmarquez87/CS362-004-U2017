CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unit1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unit2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unit3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unit4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

card1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

card2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

card3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)

card4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

unit1.out: unittest1.c dominion.o rngs.o
	rm -f dominion.gcda
	./unittest1
	gcov dominion.c -b  >> unit1.out
	cat dominion.c.gcov >> unit1.out

unit2.out: unittest2.c dominion.o rngs.o
	rm -f dominion.gcda
	./unittest2
	gcov dominion.c -b  >> unit2.out
	cat dominion.c.gcov >> unit2.out

unit3.out: unittest3.c dominion.o rngs.o
	rm -f dominion.gcda
	./unittest3
	gcov dominion.c -b  >> unit3.out
	cat dominion.c.gcov >> unit3.out

unit4.out: unittest4.c dominion.o rngs.o
	rm -f dominion.gcda
	./unittest4
	gcov dominion.c -b  >> unit4.out
	cat dominion.c.gcov >> unit4.out

card1.out: cardtest1.c dominion.o rngs.o
	rm -f dominion.gcda
	./cardtest1
	gcov dominion.c -b  >> card1.out
	cat dominion.c.gcov >> card1.out

card2.out: cardtest2.c dominion.o rngs.o
	rm -f dominion.gcda
	./cardtest2
	gcov dominion.c -b  >> card2.out
	cat dominion.c.gcov >> card2.out

card3.out: cardtest3.c dominion.o rngs.o
	rm -f dominion.gcda
	./cardtest3
	gcov dominion.c -b  >> card3.out
	cat dominion.c.gcov >> card3.out

card4.out: cardtest4.c dominion.o rngs.o
	rm -f dominion.gcda
	./cardtest4
	gcov dominion.c -b  >> card4.out
	cat dominion.c.gcov >> card4.out

randomtestcard1: randomtestcard1.c dominion.o rngs.o 
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o 
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o 
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard1.out: randomtestcard1.c dominion.o rngs.o
	rm -f dominion.gcda
	./randomtestcard1
	gcov dominion.c -b  >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c dominion.o rngs.o
	rm -f dominion.gcda
	./randomtestcard2
	gcov dominion.c -b  >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	rm -f dominion.gcda
	./randomtestadventurer
	gcov dominion.c -b  >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

myTest:
	./unittest1 &> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

# all: playdom player testDrawCard testBuyCard badTestDrawCard unit1 unit2 unit3 unit4 card1 card2 card3 card4


all: playdom player randomtestcard1 randomtestcard2 randomtestadventurer randomtestcard1.out randomtestcard2.out randomtestadventurer.out

clean:
	rm -f *.o playdom.exe playdom player player.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestcardadventurer *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
