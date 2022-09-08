#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAR 1
#define BELL 2
#define LEMON 3
#define CHERRY 4
#define RMAX 4

void main() {
	int slot1, slot2, slot3;
	char anykey;
	while (1) {
		printf("type any key to start the slot machine");
		scanf("%c", &anykey);
		srand(time(NULL));
		slot1 = 1 + (int)rand() % RMAX;
		slot2 = 1 + (int)rand() % RMAX;
		slot3 = 1 + (int)rand() % RMAX;
		if (slot1 == slot2 && slot2 == slot3 && slot1 == CHERRY)
			printf("Congratulations On A JACKPOT\n");
		else if (slot1 == CHERRY || slot2 == CHERRY || slot3 == CHERRY)
			printf("Paid Out : One DIME\n");
		else if (slot1 == slot2 && slot2 == slot3)
			printf("Paid Out : One Nickel\n");
		else printf("Sorry.Better Luck Next Time\n");
	}
}
