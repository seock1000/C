#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARR_SIZE 5

typedef struct _node {
	int key;
	int* next;
} Node;

void Link(Node node[]) {
	for (int i = 0; i < ARR_SIZE - 1; i++)
		node[i].next = &node[i + 1].key;
}

void PrintArray(Node node[]) {
	for (int i = 0; i < ARR_SIZE; i++)
		printf("i=%d key=%d next=%d Add=%d\n", i, node[i].key, node[i].next, &node[i]);
}

int main() {
	Node node[ARR_SIZE];

	for (int i = 0; i < ARR_SIZE; i++) {
		node[i].key = i;
		node[i].next = NULL;
	}

	printf("Before linking\n");
	PrintArray(node);
	printf("\n");
	Link(node);
	printf("After linking\n");
	PrintArray(node);
	printf("\n");

	return 0;
}