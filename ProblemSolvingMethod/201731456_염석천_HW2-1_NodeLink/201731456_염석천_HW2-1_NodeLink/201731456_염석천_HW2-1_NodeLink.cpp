#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM 5

struct NODE {
	int key;
	struct NODE* next;
};

void main() {
	struct NODE node[NUM];

	for (int i = 0; i < NUM; i++) {
		node[i].key = i;
		node[i].next = NULL;
	}

	printf("Before linking\n");
	for (int i = 0; i < NUM; i++) {
		printf("i=%d key=%d next=%d Add=%d\n", i, node[i].key, node[i].next, &node[i]);
	}

	for (int i = 0; i < NUM - 1; i++) {
		node[i].next = &node[i + 1];
	}

	printf("\nAfter linking\n");
	for (int i = 0; i < NUM; i++) {
		printf("i=%d key=%d next=%d Add=%d\n", i, node[i].key, node[i].next, &node[i]);
	}
}