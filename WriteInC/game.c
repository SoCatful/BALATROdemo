#include "game.h"


//spade=1 heart=2 diamond=3 club=4 lengthoflist=0
//ace = 1  2=2 >>> 10=10>>j=11,q=12,k=13
//typedef struct card {
//	int points;
//	int suit;
//	int effects;
//	int serienum;
//} CARD;

//对子=5，高牌=6，两对=7，三条=8，同花=9，顺子=10，葫芦=11，同花顺=12

CARD *StandardCards() {

	CARD *allcards = (CARD *)malloc(sizeof(CARD) * 53); // 锟斤拷锟斤拷锟节达拷
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
void SortByPoint(CARDSET set){//按点数排序
    //将set中的所有元素按照点数从小到大排序

    //冒泡排序
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

void SortBySuit(CARDSET set){ //按花色排序
    int  length  =  set[0].suit;  //  获取牌组的总牌数
    CARD  temp;

    //  使用冒泡排序按花色排序
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
void DrawCards(CARDSET curCardSet,CARDSET handcards,int nums){//抽牌
    int totalCards = curCardSet[0].points; // 获取牌组的总牌数

    // 如果请求抽取的牌数大于剩余的牌数，则直接返回
    if (nums > totalCards) {
        return;
    }

    // 遍历抽取的牌数
    for (int i = 1; i <= nums; i++) {
        int index = rand() % totalCards + 1; // 生成随机索引

        // 检查手牌中是否已经存在相同的牌
        int isDuplicate = 0;
        for (int j = 1; j <= handcards[0].points; j++) {
            if (handcards[j].points == curCardSet[index].points && handcards[j].suit == curCardSet[index].suit) {
                isDuplicate = 1;
                break;
            }
        }

        // 如果已经存在相同的牌，则重新生成随机索引
        if (isDuplicate) {
            i--;
            continue;
        }

        // 将抽到的牌添加到handcards中
        handcards[0].points++;
        handcards = realloc(handcards, sizeof(CARD) * (handcards[0].points + 1));
        handcards[handcards[0].points] = curCardSet[index];
    }

    // 更新handcards下标为0的元素
    handcards[0].points = handcards[0].points - 1;
}

CARDSET CardType(CARDSET set){//判断牌型，第0个元素存储牌型，返回所有记分的牌
    CARDSET result = (CARDSET)malloc(sizeof(CARD) * 2);
    result[0].points = 0;
    result[0].suit = 0;

    // 按照点数排序
    SortByPoint(set);

    int numPoints[15] = {0}; // 用于统计各点数的数量
    int numSuits[5] = {0}; // 用于统计各花色的数量

    // 统计点数和花色数量
    int n = set[0].points;
    for (int i = 1; i <= n; i++) {
        numPoints[set[i].points]++;
        numSuits[set[i].suit]++;
    }

    // 判断牌型
    int maxNumPoints = 0;
    int numPairs = 0;
    int numTriplets = 0;
    int isFlush = 0;
    int isStraight = 0;

    for (int i = 2; i <= 14; i++) {
        if (numPoints[i] == 4) { // 四条
            result[result[0].points + 1].points = i;
            result[0].points++;
            break;
        } else if (numPoints[i] == 3) { // 三条
            result[result[0].points + 1].points = i;
            result[0].points++;
            numTriplets++;
        } else if (numPoints[i] == 2) { // 对子
            result[result[0].points + 1].points = i;
            result[0].points++;
            numPairs++;
        } else if (numPoints[i] == 1) {
            maxNumPoints++;
        }
    }

    // 判断同花
    for (int i = 1; i <= 4; i++) {
        if (numSuits[i] == 5) {
            isFlush = 1;
            break;
        }
    }

    // 判断顺子
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

    // 返回牌型
    if (isFlush && isStraight) {
        result[0].points = 12; // 同花顺
    } else if (numTriplets && numPairs) {
        result[0].points = 11; // 葫芦
    } else if (isFlush) {
        result[0].points = 9; // 同花
    } else if (isStraight) {
        result[0].points = 10; // 顺子
    } else if (numTriplets) {
        result[0].points = 8; // 三条
    } else if (numPairs >= 2) {
        result[0].points = 7; // 两对
    } else if (numPairs == 1) {
        result[0].points = 5; // 对子
    } else {
        result[0].points = 6; // 高牌
    }

    return result;
}
int CountingPoints(CARDSET set){//基于牌型记分
	
}
CARDSET DuplicateSet(CARDSET set){
	//复制卡组，返回头指针
}
CARDSET PlayOrDiscard(CARDSET handcard){
	
}
int GetTarget(int round,int effect){
	
}
int Blind(CARDSET currentCardSet,int plays,int discards,int handcards,int round,int blindtype){
//盲注，运行阶段  卡组               出牌数    弃牌数       手牌上限      回合      盲注类型
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
		DrawCards(cardheap,handcard,cardsplayed);//致命问题：弃牌出牌？需要解决！！！
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















