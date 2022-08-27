#include <stdio.h>
#include <stdlib.h>

// Merge two sorted arrat with sorting
// input : array and index for divided area
// output : void;
void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left; // 왼쪽 블록의 시작 index
	int rIdx = mid + 1; // 오른쪽 블록의 시작 index
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1)); // 병합 정렬을 위한 메모리 공간 할당
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) { // 둘중 한 블록이 모두 정렬될 때까지
		if (arr[fIdx] <= arr[rIdx]) // 두 블록에서 가장 우선순위가 높은 값끼리 비교하여
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++]; // 마련한 메모리 공간에 데이터 정렬

		sIdx++;
	}

	if (fIdx > mid) { // 남은 데이터 마저 삽입
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else {
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i <= right; i++) // 메모리 공간에 병합 정렬한 데이터 원 배열에 저장
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) { // 분할이 완료되면 left == right 이므로,
		mid = (left + right) / 2; // 중간지점 계산

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right); // 둘로 나눠 각각 정렬

		MergeTwoArea(arr, left, mid, right);
	}
}

int main() {
	int arr[7] = { 3,2,4,1,7,5,6 };
	int i;

	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}