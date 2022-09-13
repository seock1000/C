#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MinMax(int arr[], int n, int* min, int* max) {
	for (int i = 0; i < n; i++) {
		if (arr[i] > *max)
			*max = arr[i];
		if (arr[i] < *min)
			*min = arr[i];
	}
}

int main() {
	
	int arr[10] = { 1,2,4,10,16,22,4,6,3, 88 };
	int min = arr[0];
	int max = arr[0];
	int n = 10;

	MinMax(arr, n, &min, &max);

	printf("min : %d, max : %d\n", min, max);

	return 0;
}