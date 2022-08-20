#include <stdio.h>

void BubbleSort(int arr[], int n) {
	int tmp;

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) { // ������ �� �� �� ���� ���� ���� �� ���� ũ��
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp; // ������ ��ȯ
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