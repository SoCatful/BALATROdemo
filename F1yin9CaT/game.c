#include "game.h"


//spade=1 heart=2 diamond=3 club=4 lengthoflist=0
//ace = 1  2=2 >>> 10=10>>j=11,q=12,k=13
//typedef struct card {
//	int points;
//	int suit;
//	int effects;
//	int serienum;
//} CARD;

CARD *StandardCards() {

	CARD *allcards = (CARD *)malloc(sizeof(CARD) * 53); // �����ڴ�
	if (allcards == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	allcards[0].points = 52; // first node: store the length of card set
	allcards[0].serienum = 0;
	allcards[0].suit = 0;
	allcards[0].effects = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++) {
			int serienum = 13 * i + j;
			allcards[serienum].points = j; // points 1&#126;13
			allcards[serienum].suit = i + 1; // suits 1&#126;4
			allcards[serienum].serienum = 13 * i + j; // serienum 1&#126;52
			allcards[serienum].effects = 0;
		}
	}
	return allcards;
}

void PrintCardSet(CARD *cardlist) {
	int len = cardlist[0].points;
	int iterator = 1;
	while (iterator < len + 1) {
		printf("%d-%d|", cardlist[iterator].suit, cardlist[iterator].points);
		iterator++;
	}
}
void SortByPoint(CARDSET set){//����������
	
}

void SortBySuit(CARDSET set){ //����ɫ����
	
}
void DrawCards(CARDSET curCardSet,CARDSET handcards,int nums){//����

}

CARDSET CardType(CARDSET set){//�ж����ͣ���0��Ԫ�ش洢���ͣ��������мǷֵ���

}
int CountingPoints(CARDSET set){//�������ͼǷ�
	
}
CARDSET DuplicateSet(CARDSET set){
	//���ƿ��飬����ͷָ��
}
CARDSET PlayOrDiscard(CARDSET handcard){
	
}
int GetTarget(int round,int effect){
	
}
int Blind(CARDSET currentCardSet,int plays,int discards,int handcards,int round,int blindtype){
//äע�����н׶�  ����               ������    ������       ��������      �غ�      äע����
	CARDSET cardheap = DuplicateSet(currentCardSet);
	CARD handcard[handcards];
	CARDSET cardsplayedd;
	int leftplays = plays;
	int leftdiscards = discards;
	int cardsplayed = handcards;
	int TtlPts = 0;
	int roundPts = 0;
	int Target = GetTarget(round,blindtype);
	while(1){
		DrawCards(cardheap,handcard,cardsplayed);//�������⣺���Ƴ��ƣ���Ҫ���������
		cardsplayedd = PlayOrDiscard(handcard);
		cardsplayed = cardsplayedd[0].points;
		roundPts = CountingPoints(cardsplayedd);
		TtlPts+=roundPts;
		if(TtlPts>=Target){
			return 1;//success
		}else if(leftplays == 0){
			return 0;//game over!
		}
	}
}















