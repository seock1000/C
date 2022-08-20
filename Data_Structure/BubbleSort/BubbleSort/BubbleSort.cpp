#include <stdio.h>

void BubbleSort(int arr[], int n) {
	int tmp;

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) { // 인접한 두 값 중 앞의 값이 뒤의 값 보다 크면
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp; // 데이터 교환
			}
		}
	}
}

int main() {
	int arr[4] = { 3,2,4,1 };

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}