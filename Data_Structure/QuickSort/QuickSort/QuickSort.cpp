#include <stdio.h>

// Swap data of array
// input : array and two index to swap
// ouput : void
void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// seperate array to two area
// input : array and first and last index of area to sort
// output : index of pivot
int Partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right; // pivot�� low, high ����

	while (low <= high) { // low�� high�� ������ ������
		while (pivot >= arr[low] && low <= right) // low �̵�
			low++;

		while (pivot <= arr[high] && high >= (left + 1)) // high �̵�
			high--;

		if (low <= high) // low�� high�� �������� �ʾ����� swap
			Swap(arr, low, high);
	}

	Swap(arr, left, high); // high�� pivot swap
	return high; // swap ���� pivot�� ��ġ ��ȯ
}

// Quick sort
// input : array and first and last index of array to sort
// output : void
void QuickSort(int arr[], int left, int right) {

	if (left <= right) { // ����� Ż�� ���� : left > right 
		int pivot = Partition(arr, left, right); // �����Ͽ� pivot�� ��ġ Ȯ�� ��
		QuickSort(arr, 0, pivot - 1);  
		QuickSort(arr, pivot + 1, right); // ���ҵ� �� ������ ���� ����
	}
}

int main() {
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int)-1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}