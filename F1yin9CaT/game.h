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
void SortByPoint(CARDSET set);//����������
void SortBySuit(CARDSET set);//����ɫ����
void DrawCards(CARDSET curCardSet,CARDSET handcards,int nums);//����
CARDSET CardType(CARDSET set);//�ж����ͣ���0��Ԫ�ش洢���ͣ��������мǷֵ���
int CountingPoints(CARDSET set);
CARDSET DuplicateSet(CARDSET set);
CARDSET PlayOrDiscard(CARDSET handcard);
int GetTarget(int round,int effect);
