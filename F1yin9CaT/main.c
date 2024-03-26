#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "game.h"


/*
本人会将此程序的顶层设计和思路全部放进这个注释里面。望周知

游戏：主菜单--2个选项 如果输入了退出，那么就退出主循环

开始游戏之后大致分成两种情况：盲注选择状�?-》盲注运行阶�?-�?
大概的流程是这样的：
menu（）�?



*/
typedef struct card {
	int points;
	int suit;
	int effects;
	int serienum;
} CARD;

void menu() {
	printf("------------------------------\n");
	printf("------------1.play------------\n");
	printf("------------0.exit------------\n");
	printf("------------------------------\n");
}

CARD *StandardCards() {
//	CARD AllcardList[53];
//	AllcardList[0].points   = 52;//first node: store the length of card set
//	AllcardList[0].serienum =  0;
//	AllcardList[0].suit     =  0;
//	AllcardList[0].effects  =  0;
//	for (int i = 0; i++ ; i < 4) {
//		for (int j = 1; j++ ; j < 14) {
//			int serienum = 13 * i + j;
//			AllcardList[serienum].points = j;       //points 1~13
//			AllcardList[serienum].suit   = i + 1;   //suits  1~4
//			AllcardList[serienum].serienum = 13 * i + j; //serienum 1~52
//			AllcardList[serienum].effects = 0;
//		}
//	}
//	return AllcardList;
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

int main() {
	CARD *allcards = StandardCards();
	PrintCardSet(allcards);
//    srand((unsigned)time(NULL));
//    int input = 0;
//    do
//    {
//        menu();
//        scanf("%d",&input);
//        switch (input)
//        {
//        case 1:
//            break;
//        case 0:printf("out game!\n");
//            break;
//        default:printf("reinput!");
//            break;
//        }
//    } while (input);
//    return 0;

}