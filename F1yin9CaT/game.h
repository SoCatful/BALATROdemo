//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {
	int points;
	int suit;
	int effects;
	int serienum;
} CARD;

typedef CARD* CARDSET;

CARD *StandardCards();
void PrintCardSet(CARD * );
int Blind(CARDSET currentCardSet,int plays,int discards,int handcards,int round,int effect);
void SortByPoint(CARDSET set);//按点数排序
void SortBySuit(CARDSET set);//按花色排序
void DrawCards(CARDSET curCardSet,CARDSET handcards,int nums);//抽牌
CARDSET CardType(CARDSET set);//判断牌型，第0个元素存储牌型，返回所有记分的牌
int CountingPoints(CARDSET set);
CARDSET DuplicateSet(CARDSET set);
CARDSET PlayOrDiscard(CARDSET handcard);
int GetTarget(int round,int effect);
