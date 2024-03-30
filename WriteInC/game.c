#include "game.h"


//spade=1 heart=2 diamond=3 club=4 lengthoflist=0
//ace = 1  2=2 >>> 10=10>>j=11,q=12,k=13
//typedef struct card {
//	int points;
//	int suit;
//	int effects;
//	int serienum;
//} CARD;

//����=5������=6������=7������=8��ͬ��=9��˳��=10����«=11��ͬ��˳=12

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
    //��set�е�����Ԫ�ذ��յ�����С��������

    //ð������
    int  n  =  set[0].points;
    CARD  temp;

    for  (int  i  =  1;  i  <  n;  i++)  {
        for  (int  j  =  i  +  1;  j  <=  n;  j++)  {
            if  (set[i].points  >  set[j].points)  {
                temp  =  set[i];
                set[i]  =  set[j];
                set[j]  =  temp;
            }
        }
    }

}

void SortBySuit(CARDSET set){ //����ɫ����
    int  length  =  set[0].suit;  //  ��ȡ�����������
    CARD  temp;

    //  ʹ��ð�����򰴻�ɫ����
    for  (int  i  =  1;  i  <  length;  i++)  {
        for  (int  j  =  1;  j  <  length  -  i;  j++)  {
            if  (set[j].suit  >  set[j  +  1].suit)  {
                temp  =  set[j];
                set[j]  =  set[j  +  1];
                set[j  +  1]  =  temp;
            }
        }
    }
}
void DrawCards(CARDSET curCardSet,CARDSET handcards,int nums){//����
    int totalCards = curCardSet[0].points; // ��ȡ�����������

    // ��������ȡ����������ʣ�����������ֱ�ӷ���
    if (nums > totalCards) {
        return;
    }

    // ������ȡ������
    for (int i = 1; i <= nums; i++) {
        int index = rand() % totalCards + 1; // �����������

        // ����������Ƿ��Ѿ�������ͬ����
        int isDuplicate = 0;
        for (int j = 1; j <= handcards[0].points; j++) {
            if (handcards[j].points == curCardSet[index].points && handcards[j].suit == curCardSet[index].suit) {
                isDuplicate = 1;
                break;
            }
        }

        // ����Ѿ�������ͬ���ƣ������������������
        if (isDuplicate) {
            i--;
            continue;
        }

        // ���鵽������ӵ�handcards��
        handcards[0].points++;
        handcards = realloc(handcards, sizeof(CARD) * (handcards[0].points + 1));
        handcards[handcards[0].points] = curCardSet[index];
    }

    // ����handcards�±�Ϊ0��Ԫ��
    handcards[0].points = handcards[0].points - 1;
}

CARDSET CardType(CARDSET set){//�ж����ͣ���0��Ԫ�ش洢���ͣ��������мǷֵ���
    CARDSET result = (CARDSET)malloc(sizeof(CARD) * 2);
    result[0].points = 0;
    result[0].suit = 0;

    // ���յ�������
    SortByPoint(set);

    int numPoints[15] = {0}; // ����ͳ�Ƹ�����������
    int numSuits[5] = {0}; // ����ͳ�Ƹ���ɫ������

    // ͳ�Ƶ����ͻ�ɫ����
    int n = set[0].points;
    for (int i = 1; i <= n; i++) {
        numPoints[set[i].points]++;
        numSuits[set[i].suit]++;
    }

    // �ж�����
    int maxNumPoints = 0;
    int numPairs = 0;
    int numTriplets = 0;
    int isFlush = 0;
    int isStraight = 0;

    for (int i = 2; i <= 14; i++) {
        if (numPoints[i] == 4) { // ����
            result[result[0].points + 1].points = i;
            result[0].points++;
            break;
        } else if (numPoints[i] == 3) { // ����
            result[result[0].points + 1].points = i;
            result[0].points++;
            numTriplets++;
        } else if (numPoints[i] == 2) { // ����
            result[result[0].points + 1].points = i;
            result[0].points++;
            numPairs++;
        } else if (numPoints[i] == 1) {
            maxNumPoints++;
        }
    }

    // �ж�ͬ��
    for (int i = 1; i <= 4; i++) {
        if (numSuits[i] == 5) {
            isFlush = 1;
            break;
        }
    }

    // �ж�˳��
    if (maxNumPoints == 5) {
        if ((numPoints[14] == 1 && numPoints[2] == 1 && numPoints[3] == 1 && numPoints[4] == 1 && numPoints[5] == 1) ||
            (numPoints[14] == 1 && numPoints[10] == 1 && numPoints[11] == 1 && numPoints[12] == 1 && numPoints[13] == 1)) {
            isStraight = 1;
        } else {
            for (int i = 2; i <= 10; i++) {
                if (numPoints[i] == 1 && numPoints[i + 1] == 1 && numPoints[i + 2] == 1 && numPoints[i + 3] == 1 && numPoints[i + 4] == 1) {
                    isStraight = 1;
                    break;
                }
            }
        }
    }

    // ��������
    if (isFlush && isStraight) {
        result[0].points = 12; // ͬ��˳
    } else if (numTriplets && numPairs) {
        result[0].points = 11; // ��«
    } else if (isFlush) {
        result[0].points = 9; // ͬ��
    } else if (isStraight) {
        result[0].points = 10; // ˳��
    } else if (numTriplets) {
        result[0].points = 8; // ����
    } else if (numPairs >= 2) {
        result[0].points = 7; // ����
    } else if (numPairs == 1) {
        result[0].points = 5; // ����
    } else {
        result[0].points = 6; // ����
    }

    return result;
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















