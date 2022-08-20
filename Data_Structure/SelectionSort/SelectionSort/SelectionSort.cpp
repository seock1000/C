#include <stdio.h>

void SelectionSort(int arr[], int n) {
	int maxIdx;
	int tmp;

	for (int i = 0; i < n-1; i++) {
		maxIdx = i; // ������ �ȵ� �迭�� ���� �� index ����
		for (int j = i + 1; j < n; j++) {
			if (arr[maxIdx] > arr[j])
				maxIdx = j; // maxIdx�� ���� �������� ���� �� ������ ������ index ����
		}
		tmp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = tmp; // ������ ��ȯ
	}
}

int main() {
	int arr[] = { 3,4,2,1 };
	
	SelectionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}