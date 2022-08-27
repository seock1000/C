#include <stdio.h>
#include <stdlib.h>

// Merge two sorted arrat with sorting
// input : array and index for divided area
// output : void;
void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left; // ���� ����� ���� index
	int rIdx = mid + 1; // ������ ����� ���� index
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1)); // ���� ������ ���� �޸� ���� �Ҵ�
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) { // ���� �� ����� ��� ���ĵ� ������
		if (arr[fIdx] <= arr[rIdx]) // �� ��Ͽ��� ���� �켱������ ���� ������ ���Ͽ�
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++]; // ������ �޸� ������ ������ ����

		sIdx++;
	}

	if (fIdx > mid) { // ���� ������ ���� ����
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else {
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i <= right; i++) // �޸� ������ ���� ������ ������ �� �迭�� ����
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) { // ������ �Ϸ�Ǹ� left == right �̹Ƿ�,
		mid = (left + right) / 2; // �߰����� ���

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right); // �ѷ� ���� ���� ����

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