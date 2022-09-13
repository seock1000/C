#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 100

void InputList(int arr[], int n, FILE* fp) {

	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d", &arr[i]);
		if (arr[i] > 100000 || arr[i] < 0) { 
			printf("Wrong Input!\n");
			free(arr);
			exit(-1);
		}
	}
}

void BubbleSort(int arr[], int n) {
	int i, j;
	int tmp;

	for (i = 0; i < n; i++) {
		for (j = 1; j < n - i; j++) {
			if (arr[j] > arr[j - 1]) {
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

int ComputeAverage(int arr[], int n) {
	int avg = 0;
	int i;

	for (i = 0; i < n; i++)
		avg += arr[i];
	
	return avg / n;
}

int ComputeTotalMovingMoney(int arr[], int avg, int n) {

	int totalMovingMoney = 0;
	int amountForRich;

	if (avg % 10 == 0) amountForRich = avg;
	else {
		avg -= (avg % 10);
		amountForRich = avg + 10;
	}

	BubbleSort(arr, n);

	int high = 0;
	int low = n - 1;
	for (;;) {
		if (arr[high] <= amountForRich) break;

		int moneyToAlloc = arr[high] - amountForRich;
		totalMovingMoney += moneyToAlloc;

		while (moneyToAlloc > 0) {
			int need = avg - arr[low];
			if (need <= moneyToAlloc) {
				arr[low] += need;
				moneyToAlloc -= need;
				low++;
			}
			else {
				arr[low] += moneyToAlloc;
				moneyToAlloc = 0;
			}
		}
		high++;
	}

	return totalMovingMoney;
}

int main() {
	FILE* fp;

	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("File open fail!\n");
		exit(-1);
	}

	int n;

	while (true) {
		fscanf(fp, "%d", &n);
		
		if (n <= 0) break;
		else if (n > 100) {
			printf("Wrong Input!\n");
			exit(-1);
		}

		int arr[ARR_SIZE]; 
		InputList(arr, n, fp);

		printf("\\%d\n", ComputeTotalMovingMoney(arr, ComputeAverage(arr, n), n));
		
	}

	fclose(fp);

	return 0;
}