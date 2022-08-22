#include <stdio.h>

void InsertionSort(int arr[], int n) {
	int i, j;
	int insData;

	for (i = 0; i < n; i++) {
		insData = arr[i];
		for (j = i-1; j >= 0; j--) {
			if (insData < arr[j])
				arr[j + 1] = arr[j]; // 비교대상 한 칸 뒤로
			else 
				break; // 삽입위치 찾으면 탈출
		}
		arr[j+1] = insData;
	}
}

int main() {
	int arr[] = { 5, 3, 2, 4, 1 };

	InsertionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}