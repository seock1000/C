#include <stdio.h>
#include "../../UsefulHeap/UsefulHeap/UsefulHeap.h"

int PriComp(HData n1, HData n2) {
	return n2 - n1; // 오름차순 정렬을 위한 우선순위 반환
}

void HeapSort(int arr[], int n, PriorityComp pc) {
	Heap heap;
	int i;

	HeapInit(&heap, pc);

	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]); // 힙 구성

	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap); // 힙에서 데이터를 빼오며 정렬
}

int main() {
	int arr[4] = { 3,4,2,1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
