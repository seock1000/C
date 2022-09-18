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

int ComputeAverage(int arr[], int n) {
	int avg = 0;
	int i;

	for (i = 0; i < n; i++)
		avg += arr[i];
	
	return avg / n;
}

int ComputeTotalMovingMoney(int arr[], int avg, int n) {

	int totalMovingMoney = 0;
	int cnt, i;

	if (avg % 10 == 0) cnt = 0;
	else {
		if ((((avg % 10) * n) % 10) == 0)
			cnt = (((avg % 10) * n) / 10);
		else
			cnt = (((avg % 1) * n) / 10) + 1;
	}

	avg -= (avg % 10);

	for (i = 0; i < n; i++) {
		if (arr[i] >= avg + 10) {
			if (cnt > 0) {
				totalMovingMoney += arr[i] - (avg + 10);
				cnt--;
			}
			else totalMovingMoney += arr[i] - avg;
		}
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
		if (fscanf(fp, "%d", &n) == EOF || n <= 0) break;
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