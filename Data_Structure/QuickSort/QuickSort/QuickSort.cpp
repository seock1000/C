#include <stdio.h>

// Swap data of array
// input : array and two index to swap
// ouput : void
void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void SelectMidValue(int arr[], int left, int right) {
	int mid = (left + right) / 2;
	if (arr[left] < arr[right]) {
		if (arr[right] < arr[mid])
			Swap(arr, left, right);
		else if (arr[left] < arr[mid])
			Swap(arr, left, mid);
	}
	else {
		if (arr[right] > arr[mid])
			Swap(arr, left, right);
		else if (arr[left] > arr[mid])
			Swap(arr, left, mid);
	}
}

// seperate array to two area
// input : array and first and last index of area to sort
// output : index of pivot
int Partition(int arr[], int left, int right) {
	SelectMidValue(arr, left, right);
	int pivot = arr[left];
	int low = left + 1;
	int high = right; // pivot과 low, high 설정

	printf("pivot : %d \n", pivot);

	while (low <= high) { // low와 high가 교차될 때까지
		while (pivot >= arr[low] && low <= right) // low 이동
			low++;

		while (pivot <= arr[high] && high >= (left + 1)) // high 이동
			high--;

		if (low <= high) // low와 high가 교차되지 않았으면 swap
			Swap(arr, low, high);
	}

	Swap(arr, left, high); // high와 pivot swap
	return high; // swap 이후 pivot의 위치 반환
}

// Quick sort
// input : array and first and last index of array to sort
// output : void
void QuickSort(int arr[], int left, int right) {

	if (left <= right) { // 재귀의 탈출 조건 : left > right 
		int pivot = Partition(arr, left, right); // 분할하여 pivot의 위치 확정 후
		QuickSort(arr, 0, pivot - 1);  
		QuickSort(arr, pivot + 1, right); // 분할된 두 영역에 대해 정렬
	}
}

int main() {
	int arr[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int)-1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}