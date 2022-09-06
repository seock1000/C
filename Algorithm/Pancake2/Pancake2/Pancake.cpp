#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../../Data_Structure/UsefulHeap/UsefulHeap/UsefulHeap.h"

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

int StackPancake(int arr[], int sequence[], Heap* heap, int n) {
	int key, i;
	int arrLen = n;
	int cnt = 0;
	n = n - 1;

	while (!HIsEmpty(heap)) {
		key = HDelete(heap);
		if (n == 0) {
			sequence[cnt++] = 0;
			break;
		}
		if (arr[n] != key) {
			for (i = n - 1; i >= 0; i--) {
				if (arr[i] == key) {
					if (i == 0) {
						FlipPancake(arr, n);
						sequence[cnt++] = arrLen - n;
					}
					else {
						FlipPancake(arr, i);
						FlipPancake(arr, n);
						sequence[cnt++] = arrLen - i;
						sequence[cnt++] = arrLen - n;
						break;
					}
				}
			}
		}
		n--;
	}

	return cnt;
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
	int n, seqLen;
	int cnt = 0;
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

		for (i = 0; i < cnt; i++) {
			printf("%d ", arr[i]);
		}

		seqLen = StackPancake(arr, sequence, &heap, cnt);

		printf("(");
		for (i = 0; i < cnt; i++) {
			if (i == cnt - 1)
				printf("%d", arr[i]);
			else
				printf("%d ", arr[i]);
		}
		printf(")\n");

		for (i = 0; i < seqLen; i++)
			printf("%d ", sequence[i]);

		printf("\n");
	}

	fclose(fp);

	return 0;
}