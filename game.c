#include "game.h"
#include <stdio.h>

//spade=1 heart=2 diamond=3 club=4 lengthoflist=0
//ace = 1  2=2 >>> 10=10>>j=11,q=12,k=13
//typedef struct card {
//	int points;
//	int suit;
//	int effects;
//	int serienum;
//} CARD;

CARD *StandardCards() {
	CARD AllcardList[53];
	AllcardList[0].points   = 52;//first node: store the length of card set
	AllcardList[0].serienum =  0;
	AllcardList[0].suit     =  0;
	AllcardList[0].effects  =  0;
	for (int i = 0; i++ ; i < 4) {
		for (int j = 1; j++ ; j < 14) {
			int serienum = 13 * i + j;
			AllcardList[serienum].points = j;       //points 1~13
			AllcardList[serienum].suit   = i + 1;   //suits  1~4
			AllcardList[serienum].serienum = 13 * i + j; //serienum 1~52
			AllcardList[serienum].effects = 0;
		}
	}
	return AllcardList;
}

void PrintCardSet(CARD *cardlist) {
	int len = cardlist[0].points;
	int iterator = 1;
	while (iterator < len + 1) {
		printf("%d-%d|", cardlist[iterator].suit, cardlist[iterator].points);
		iterator++;
	}
}

