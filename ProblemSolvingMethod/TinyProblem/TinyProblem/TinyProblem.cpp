#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int FindMaxValueIdx(int arr[], int idxArr[], int n) {
	int i, maxCnt = 1;
	int max = arr[0];
	idxArr[0] = 0;

	for (i = 1; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
			idxArr[0] = i;
			maxCnt = 1;
		}
		else if (max == arr[i]) {
			idxArr[maxCnt] = i;
			maxCnt++;
		}
	}

	return maxCnt;
}

int FindMinValueIdx(int arr[], int idxArr[], int n) {
	int i, minCnt = 1;
	int min = arr[0];
	idxArr[0] = 0;

	for (i = 1; i < n; i++) {
		if (min > arr[i]) {
			min = arr[i];
			idxArr[0] = i;
			minCnt = 1;
		}
		else if (min == arr[i]) {
			idxArr[minCnt] = i;
			minCnt++;
		}
	}

	return minCnt;
}

int main() {
	int age[100];
	int score[100];
	int cnt = 0, i;
	int idx[100];

	for (i = 0; i < 100; i++) {
		printf("Put age and score pair (End : -1 -1) : ");
		scanf("%d %d", &age[i], &score[i]);
		if (age[i] == -1 && score[i] == -1)
			break;
		cnt++;
	}

	if (cnt == 0) {
		printf("Data not exist.\n");
		exit(-1);
	}

	for (i = 0; i < FindMaxValueIdx(age, idx, cnt); i++) {
		printf("Oldest age(%d) score as %d\n", age[idx[i]], score[idx[i]]);
	}

	for (i = 0; i < FindMinValueIdx(age, idx, cnt); i++) {
		printf("Youngest age(%d) score as %d\n", age[idx[i]], score[idx[i]]);
	}

	for (i = 0; i < FindMaxValueIdx(score, idx, cnt); i++) {
		printf("Max score(%d) age as %d\n", score[idx[i]], age[idx[i]]);
	}

	for (i = 0; i < FindMinValueIdx(score, idx, cnt); i++) {
		printf("Min score(%d), age as %d\n", score[idx[i]], age[idx[i]]);
	}

	return 0;
}