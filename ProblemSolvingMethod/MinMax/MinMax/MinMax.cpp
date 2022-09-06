#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, num;
	int arr[100];
	int maxIdx;

	for (i = 0; i < 100; i++) {
		printf("Please type an positive integer : ");
		scanf("%d", &num);
		if (num == -1)
			break;
		
		arr[i] = num;

		if (i == 0) {
			maxIdx = 0;
		}
		else if (arr[maxIdx] < arr[i])
			maxIdx = i;
	}

	printf("Max Index : %d\n", maxIdx);
	printf("Max Value : %d\n", arr[maxIdx]);

	return 0;
}
