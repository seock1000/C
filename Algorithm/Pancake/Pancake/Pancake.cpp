#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

// 예외처리 추가하기

int main() {
	FILE* fp;

	if ((fp = fopen("input.txt", "r")) == NULL) {
		printf("File open fail.\n");
		exit(-1);
	}

	int arr[30];
	int sequence[100];
	Heap heap;
	int n, cnt;
	int i;
	int value = fgetc(fp);

	while (value != EOF) {
		HeapInit(&heap, Comp);
		cnt = 0;

		while (value != EOF && value != '\n') {
			if (isdigit(value)) {
				int nextValue = fgetc(fp);
				if (isdigit(nextValue)) {
					nextValue = fgetc(fp);
					n = 10;
				}
				else
					n = value - '0';
				value = nextValue;
				arr[cnt++] = n;
				HInsert(&heap, n);
			}
			else
				value = fgetc(fp);
		}

		if (value != EOF)
			value = fgetc(fp);

		ARR_LEN = cnt;
		
		cntSequence = 0;

		for (i = 0; i < cnt; i++)
			printf("%d ", arr[i]);

		StackPancake(arr, sequence, &heap, cnt - 1);

		printf("(");
		for (i = 0; i < cnt; i++) {
			if(i == cnt - 1)
				printf("%d", arr[i]);
			else
				printf("%d ", arr[i]);
		}
		printf(")\n");

		for (i = 0; i < cntSequence; i++)
			printf("%d ", sequence[i]);

		printf("\n");
	}

	fclose(fp);

	return 0;
}