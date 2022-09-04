#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "../../ListBaseQueue/ListBaseQueue/ListBaseQueue.h"

#define BUCKET_NUM 10

// sort array
// input : array, number of data, length of the longest data
// output : void
void RadixSort(int arr[], int num, int maxLen) { // ���� �� �������� ���̸� maxLen���� ����
	Queue buckets[BUCKET_NUM]; // ť�� �迭�� ��Ŷ ����
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// ��Ŷ �ʱ�ȭ
	for (bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	// ���� �� �������� ���̸�ŭ �ݺ�
	for (pos = 0; pos < maxLen; pos++) {
		// ���� ����� ����ŭ �ݺ�
		for (di = 0; di < num; di++) {
			// �ش��ϴ� �ڸ��� �����Ͽ� ��Ŷ�� ����
			radix = (arr[di] / divfac) % 10;
			Enqueue(&buckets[radix], arr[di]);
		}
		// ��Ŷ �� ��ŭ �ݺ�
		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
			// ��Ŷ�� ����� �����͸� ������� ���� arr�� ���ʴ�� ����
			while (!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}
		// �ڸ��� ���� ���� ��Ģ�� ���� ������ ����
		divfac *= 10;
	}
}

int main() {
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}