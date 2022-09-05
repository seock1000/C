#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "../../../Data_Structure/UsefulHeap/UsefulHeap/UsefulHeap.h"


int cntSequence = 0;
int ARR_LEN;

int Comp(int n1, int n2) {
	return n1 - n2;
}

void FlipPancake(int arr[], int n) {
	int tmp;
	int i;

	for (i = 0; i < (n + 1) / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[n - i];
		arr[n - i] = tmp;
	}
}

void StackPancake(int arr[], int sequen[], Heap* heap, int n) {
	if (n == 1) {
		sequen[cntSequence++] = 0;
		return;
	}

	int key = HDelete(heap);
	int tmp = n;

	if (arr[n] != key) {
		while (arr[tmp] != key && tmp >= 0) {
			tmp--;
		}
		if (tmp == 0) {
			FlipPancake(arr, n);
			sequen[cntSequence++] = ARR_LEN - n;
		}
		else {
			FlipPancake(arr, tmp);
			FlipPancake(arr, n);
			sequen[cntSequence++] = ARR_LEN - tmp;
			sequen[cntSequence++] = ARR_LEN - n;
		}
	}

	StackPancake(arr, sequen, heap, n - 1);
}

int main() {
	FILE* fp;

	if ((fp = fopen("input.txt", "r")) == NULL) {
		printf("File open fail.\n");
		exit(-1);
	}

	int arr[30];
	int sequence[100];
	Heap heap;
	int n, cnt = 0;
	int i;

	HeapInit(&heap, Comp);

	for (;;) {	
		if (fscanf(fp, "%d", &n) == EOF)
			break;
		arr[cnt++] = n;
		HInsert(&heap, n);
	}
	ARR_LEN = cnt;

	for (i = 0; i < cnt; i++)
		printf("%d ", arr[i]);

	StackPancake(arr, sequence, &heap, cnt - 1);

	printf("(");
	for (i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}
	printf(")\n");

	for (i = 0; i < cntSequence; i++)
		printf("%d ", sequence[i]);

	printf("\n");

	fclose(fp);

	return 0;
}