#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void InputData(FILE* fp, int* time, int* fine, int n) {
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %d", &time[i], &fine[i]);
	}
}

int MinIdx(int* arr, int n) {
	int minIdx = 0;
	for (int i = 0; i < n; i++) {
		if (arr[minIdx] > arr[i])
			minIdx = i;
	}

	return minIdx;
}

void FindSequence(int* time, int* fine, int n, int* seq) {
	int* totalFine = (int*)malloc(sizeof(int) * n);
	int i, j;

	for (i = 0; i < n; i++)
		seq[i] = i;

	int tmp;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			if (time[seq[j]] * fine[seq[j + 1]] > time[seq[j + 1]] * fine[seq[j]]) {
				tmp = seq[j];
				seq[j] = seq[j + 1];
				seq[j + 1] = tmp;
			}
		}
	}
}

int main() {
	FILE* fp;
	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("File open failed!\n");
		exit(-1);
	}
	int n;

	fscanf(fp, "%d", &n);
	if (n < 1 || n > 1000) {
		printf("Wrong Input!\n");
		exit(-1);
	}

	while (n-- > 0) {
		int task;
		fgetc(fp);
		fscanf(fp, "%d", &task);
		int* time = (int*)malloc(sizeof(int) * task);
		int* fine = (int*)malloc(sizeof(int) * task);
		int* seq = (int*)malloc(sizeof(int) * task);

		InputData(fp, time, fine, task);
		FindSequence(time, fine, task, seq);

		for (int i = 0; i < task; i++) {
			printf("%d ", seq[i] + 1);
		}
		printf("\n");

		free(time);
		free(fine);
		free(seq);
	}

	return 0;
}