#include <stdio.h>
#include "LinkedList.h"

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main() {
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede); // 정렬의 기준 등록

	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터의 수 : %d\n", LCount(&list));
	// 데이터 전체 출력
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");
	// 22인 데이터 삭제
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}

	printf("현재 데이터의 수 : %d\n", LCount(&list));
	// 데이터 전체 출력
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");

	return 0;
}