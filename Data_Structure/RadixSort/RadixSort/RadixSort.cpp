#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "../../ListBaseQueue/ListBaseQueue/ListBaseQueue.h"

#define BUCKET_NUM 10

// sort array
// input : array, number of data, length of the longest data
// output : void
void RadixSort(int arr[], int num, int maxLen) { // 가장 긴 데이터의 길이를 maxLen으로 전달
	Queue buckets[BUCKET_NUM]; // 큐의 배열로 버킷 생성
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// 버킷 초기화
	for (bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	// 가장 긴 데이터의 길이만큼 반복
	for (pos = 0; pos < maxLen; pos++) {
		// 정렬 대상의 수만큼 반복
		for (di = 0; di < num; di++) {
			// 해당하는 자릿수 추출하여 버킷에 저장
			radix = (arr[di] / divfac) % 10;
			Enqueue(&buckets[radix], arr[di]);
		}
		// 버킷 수 만큼 반복
		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
			// 버킷에 저장된 데이터를 순서대로 꺼내 arr에 차례대로 저장
			while (!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}
		// 자릿수 추출 연산 규칙에 따라 피제수 증가
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