#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int FindMax(int arr[], int n) {
	int max = arr[0];
	
	for (int i = 0; i <= n; i++) {
		if (max < arr[i])
			max = arr[i];
	}

	return max;
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

int StackPancake(int arr[], int sequence[], int n) {
	int key, i;
	int arrLen = n;
	int cnt = 0;
	n = n - 1;

	while (n >= 0) {
		key = FindMax(arr, n);
		if (n == 0) {
			sequence[cnt++] = 0;
			break;
		}
		if (arr[n] == key) {
			n--;
			continue;
		}
		else {
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
			n--;
		}
	}

	return cnt;
}

int ChangeStringToArray(int arr[], char str[]) {
	int cnt = 0;
	int arrCnt = 0;
	int n;

	while (str[cnt] != ' ' && str[cnt] != '\n' && str[cnt] != NULL) {
		char eleNum[100] = { NULL, };
		int eleCnt = 0;

		while (isdigit(str[cnt])) {
			eleNum[eleCnt] = str[cnt];
			cnt++;
			eleCnt++;
		}
		if (str[cnt] != ' ' && str[cnt] != '\n' && str[cnt] != NULL)
			return -1;

		else if (str[cnt] == ' ')
			cnt++;

		n = 0;
		int mul = 1;

		while (eleCnt > 0) {
			n += (eleNum[eleCnt - 1] - '0') * mul;
			eleCnt--;
			mul *= 10;
		}

		if (n > 10 || arrCnt > 30)
			return -1;

		arr[arrCnt++] = n;
	}

	return arrCnt;
}

int main() {
	FILE* fp;

	if ((fp = fopen("input.txt", "r")) == NULL) {
		printf("File open fail.\n");
		exit(-1);
	}

	int arr[30];
	char str[100] = {NULL,};
	int sequence[100];
	int n, seqLen;
	int cnt = 0;
	int i;

	while (fgets(str, 100, fp) != NULL) {
		
		int arrCnt = ChangeStringToArray(arr, str);

		if (arrCnt == -1) {
			printf("Wrong Input!\n");
			exit(-1);
		}

		for (i = 0; i < arrCnt; i++) {
			printf("%d ", arr[i]);
		}

		seqLen = StackPancake(arr, sequence, arrCnt);

		printf("(");
		for (i = 0; i < arrCnt; i++) {
			if (i == arrCnt - 1)
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

//	getchar();
//	system("pause > nul");

	return 0;
}