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

CARD *StandardCards();
void PrintCardSet(CARD * );
