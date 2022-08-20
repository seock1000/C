#include <stdio.h>

void SelectionSort(int arr[], int n) {
	int maxIdx;
	int tmp;

	for (int i = 0; i < n-1; i++) {
		maxIdx = i; // 정렬이 안된 배열의 가장 앞 index 저장
		for (int j = i + 1; j < n; j++) {
			if (arr[maxIdx] > arr[j])
				maxIdx = j; // maxIdx에 남은 데이터중 가장 앞 순서의 데이터 index 저장
		}
		tmp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = tmp; // 데이터 교환
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