#include <stdio.h>
#include "CLinkedList.h"

int main() {
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	// 데이터 입력
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// 리스트를 3번 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		
		for (i = 0; i < LCount(&list) * 3 - 1; i++) {
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	// 데이터 중 2의 배수를 삭제
	nodeNum = LCount(&list);

	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (i = 0; i < nodeNum - 1; i++) {
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// 리스트를 1번 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}

	return 0;
}